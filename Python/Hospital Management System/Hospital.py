from datetime import datetime

class Doctor:
    doctor_id_counter = 1

    def __init__(self, name, specialization):
        self.doctor_id = Doctor.doctor_id_counter
        Doctor.doctor_id_counter += 1
        self.name = name
        self.specialization = specialization

    def to_string(self):
        return f"{self.doctor_id},{self.name},{self.specialization}"

    @classmethod
    def from_string(cls, string):
        doctor_id, name, specialization = string.strip().split(',')
        return cls(name, specialization)

class Patient:
    patient_id_counter = 1

    def __init__(self, name, age, gender, contact, room_number, doctor_id=None, appointment_time=None):
        self.patient_id = Patient.patient_id_counter
        Patient.patient_id_counter += 1
        self.name = name
        self.age = age
        self.gender = gender
        self.contact = contact
        self.room_number = room_number
        self.recommended_doctor = None
        self.appointment_time = None
        self.bills = []

        if doctor_id is not None:
            self.recommend_doctor(doctor_id, appointment_time)

    def recommend_doctor(self, doctor_id, appointment_time):
        self.recommended_doctor = doctor_id
        try:
            self.appointment_time = datetime.strptime(appointment_time, "%Y-%m-%d %H:%M")
        except ValueError:
            self.appointment_time = None

    def add_bill(self, item, cost):
        current_time = datetime.now().strftime("%Y-%m-%d %H:%M")
        self.bills.append({"item": item, "cost": cost, "time": current_time})

    def list_bills(self):
        print("Bills for Patient ID:", self.patient_id)
        total_cost = 0
        for bill in self.bills:
            item, cost, time = bill["item"], bill["cost"], bill["time"]
            print(f"Item: {item}, Cost: ${cost}, Time: {time}")
            total_cost += cost
        print(f"Total Cost: ${total_cost}")

    def to_string(self):
        bill_strings = [f"{bill['item']},{bill['cost']},{bill['time']}" for bill in self.bills]
        bill_data = "|".join(bill_strings)
        doctor_data = f"{self.recommended_doctor},{self.appointment_time.strftime('%Y-%m-%d %H:%M')}" if self.recommended_doctor else ""
        return f"{self.patient_id},{self.name},{self.age},{self.gender},{self.contact},{self.room_number},{doctor_data},{bill_data}"

    @classmethod
    def from_string(cls, string):
        data = string.strip().split(',')
        patient_id, name, age, gender, contact, room_number, doctor_data, bill_data = data
        doctor_id, appointment_time = doctor_data.split(',') if doctor_data else (None, None)
        patient = cls(name, age, gender, contact, room_number, doctor_id, appointment_time)
        if bill_data:
            bills = bill_data.split('|')
            for bill in bills:
                item, cost, time = bill.split(',')
                patient.add_bill(item, float(cost))
        return patient

class Hospital:
    def __init__(self):
        self.name = "Joypurhat Government Hospital"
        self.patients = []
        self.doctors = []

    def add_patient(self, patient):
        self.patients.append(patient)
        print(f"Patient ID: {patient.patient_id} added successfully!")

    def list_patients(self):
        print("\nPatients at", self.name, "Hospital:")
        for patient in self.patients:
            print(f"Patient ID: {patient.patient_id}, Name: {patient.name}, Age: {patient.age}, Gender: {patient.gender}, Contact: {patient.contact}, Room Number: {patient.room_number}")

    def add_doctor(self, doctor):
        self.doctors.append(doctor)
        print(f"Doctor ID: {doctor.doctor_id} added successfully!")

    def list_doctors(self):
        print("\nDoctors at", self.name, "Hospital:")
        for doctor in self.doctors:
            print(f"Doctor ID: {doctor.doctor_id}, Name: {doctor.name}, Specialization: {doctor.specialization}")

    def save_patients_to_file(self):
        with open("patient.txt", "w") as file:
            for patient in self.patients:
                file.write(patient.to_string() + "\n")

    def load_patients_from_file(self):
        try:
            with open("patient.txt", "r") as file:
                lines = file.readlines()
                self.patients = [Patient.from_string(line) for line in lines]
        except FileNotFoundError:
            self.patients = []

    def save_doctors_to_file(self):
        with open("doctor.txt", "w") as file:
            for doctor in self.doctors:
                file.write(doctor.to_string() + "\n")

    def load_doctors_from_file(self):
        try:
            with open("doctor.txt", "r") as file:
                lines = file.readlines()
                self.doctors = [Doctor.from_string(line) for line in lines]
        except FileNotFoundError:
            self.doctors = []

    def save_bills_to_file(self):
        with open("billing.txt", "w") as file:
            for patient in self.patients:
                for bill in patient.bills:
                    file.write(f"{patient.patient_id},{bill['item']},{bill['cost']},{bill['time']}\n")

    def load_bills_from_file(self):
        try:
            with open("billing.txt", "r") as file:
                lines = file.readlines()
                for line in lines:
                    data = line.strip().split(',')
                    patient_id, item, cost, time = data
                    for patient in self.patients:
                        if patient.patient_id == int(patient_id):
                            patient.add_bill(item, float(cost))
        except FileNotFoundError:
            pass

def main():
    hospital = Hospital()
    hospital.load_patients_from_file()
    hospital.load_doctors_from_file()
    hospital.load_bills_from_file()

    while True:
        print("\nHospital Management System")
        print("1. Add Patient")
        print("2. List Patients")
        print("3. Recommend Doctor for Patient")
        print("4. Add Bill for Patient")
        print("5. List Bills for Patient")
        print("6. Add Doctor")
        print("7. List Doctors")
        print("8. Exit")
        choice = input("Enter your choice: ")

        if choice == '1':
            name = input("Enter patient name: ")
            age = input("Enter patient age: ")
            gender = input("Enter patient gender: ")
            contact = input("Enter patient contact number: ")
            room_number = input("Enter room number: ")
            doctor_id = input("Enter doctor ID (leave blank for none): ")
            appointment_time = input("Enter appointment date and time (YYYY-MM-DD HH:MM, leave blank for none): ")

            patient = Patient(name, age, gender, contact, room_number, doctor_id, appointment_time)
            hospital.add_patient(patient)
            hospital.save_patients_to_file()

        elif choice == '2':
            hospital.list_patients()

        elif choice == '3':
            patient_id = int(input("Enter patient ID to recommend a doctor: "))
            found_patient = None
            for patient in hospital.patients:
                if patient.patient_id == patient_id:
                    found_patient = patient
                    break

            if found_patient:
                doctor_id = int(input("Enter doctor ID to recommend: "))
                found_doctor = None
                for doctor in hospital.doctors:
                    if doctor.doctor_id == doctor_id:
                        found_doctor = doctor
                        break

                if found_doctor:
                    appointment_time = input("Enter appointment date and time (YYYY-MM-DD HH:MM): ")
                    try:
                        appointment_time = datetime.strptime(appointment_time, "%Y-%m-%d %H:%M")
                        found_patient.recommend_doctor(doctor_id, appointment_time)
                        print(f"Doctor recommended successfully for {found_patient.name} on {appointment_time}.")
                    except ValueError:
                        print("Invalid date format. Please use YYYY-MM-DD HH:MM.")
                else:
                    print("Doctor not found.")
            else:
                print("Patient not found.")

        elif choice == '4':
            patient_id = int(input("Enter patient ID to add a bill: "))
            found_patient = None
            for patient in hospital.patients:
                if patient.patient_id == patient_id:
                    found_patient = patient
                    break

            if found_patient:
                item = input("Enter bill item: ")
                cost = float(input("Enter bill cost: $"))
                found_patient.add_bill(item, cost)
                print("Bill added successfully!")
                hospital.save_bills_to_file()
            else:
                print("Patient not found.")

        elif choice == '5':
            patient_id = int(input("Enter patient ID to list bills: "))
            found_patient = None
            for patient in hospital.patients:
                if patient.patient_id == patient_id:
                    found_patient = patient
                    break

            if found_patient:
                found_patient.list_bills()
            else:
                print("Patient not found.")

        elif choice == '6':
            name = input("Enter doctor name: ")
            specialization = input("Enter doctor specialization: ")
            doctor = Doctor(name, specialization)
            hospital.add_doctor(doctor)
            hospital.save_doctors_to_file()

        elif choice == '7':
            hospital.list_doctors()

        elif choice == '8':
            print("Exiting the Hospital Management System. Goodbye!")
            break

        else:
            print("Invalid choice. Please select a valid option.")

if __name__ == "__main__":
    main()
