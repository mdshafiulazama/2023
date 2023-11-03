#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

class Doctor {
public:
    static int doctor_id_counter;
    int doctor_id;
    string name;
    string specialization;

    Doctor(string n, string spec) : name(n), specialization(spec) {
        doctor_id = ++doctor_id_counter;
    }

    void display() const {
        cout << "Doctor ID: " << doctor_id << ", Name: " << name << ", Specialization: " << specialization << endl;
    }
};

int Doctor::doctor_id_counter = 0;

class Patient {
public:
    static int patient_id_counter;
    int patient_id;
    string name;
    int age;
    string gender;
    string contact;
    string room_number;
    int recommended_doctor_id;
    time_t appointment_time;
    vector<pair<string, float>> bills;

    Patient(string n, int a, string g, string c, string room, int doc_id = -1, time_t app_time = 0)
        : name(n), age(a), gender(g), contact(c), room_number(room), recommended_doctor_id(doc_id), appointment_time(app_time) {
        patient_id = ++patient_id_counter;
    }

    void recommendDoctor(int doc_id, time_t app_time) {
        recommended_doctor_id = doc_id;
        appointment_time = app_time;
    }

    void addBill(const string& item, float cost) {
        bills.push_back(make_pair(item, cost));
    }

    void display() const {
        cout << "Patient ID: " << patient_id << ", Name: " << name << ", Age: " << age << ", Gender: " << gender << ", Contact: " << contact << ", Room Number: " << room_number << endl;
    }

    void listBills() const {
        cout << "Bills for Patient ID: " << patient_id << endl;
        float totalCost = 0.0;
        for (const auto& bill : bills) {
            cout << "Item: " << bill.first << ", Cost: $" << bill.second << endl;
            totalCost += bill.second;
        }
        cout << "Total Cost: $" << totalCost << endl;
    }

    // Define these functions as const to allow calling them on const objects
    void recommendDoctor(int doc_id, time_t app_time) const {
        const_cast<Patient*>(this)->recommendDoctor(doc_id, app_time);
    }

    void addBill(const string& item, float cost) const {
        const_cast<Patient*>(this)->addBill(item, cost);
    }
};

int Patient::patient_id_counter = 0;

class Hospital {
private:
    string name;
    vector<Patient> patients;
    vector<Doctor> doctors;

public:
    Hospital(string hospitalName) : name(hospitalName) {}

    void addPatient(const Patient& patient) {
        patients.push_back(patient);
        cout << "Patient ID: " << patient.patient_id << " added successfully!" << endl;
    }

    void listPatients() const {
        cout << "\nPatients at " << name << " Hospital:" << endl;
        for (const auto& patient : patients) {
            patient.display();
        }
    }

    void addDoctor(const Doctor& doctor) {
        doctors.push_back(doctor);
        cout << "Doctor ID: " << doctor.doctor_id << " added successfully!" << endl;
    }

    void listDoctors() const {
        cout << "\nDoctors at " << name << " Hospital:" << endl;
        for (const auto& doctor : doctors) {
            doctor.display();
        }
    }

    const vector<Patient>& getPatients() const {
        return patients;
    }
};

int main() {
    Hospital hospital("Joypurhat Government Hospital");

    while (true) {
        cout << "\nHospital Management System" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. List Patients" << endl;
        cout << "3. Recommend Doctor for Patient" << endl;
        cout << "4. Add Bill for Patient" << endl;
        cout << "5. List Bills for Patient" << endl;
        cout << "6. Add Doctor" << endl;
        cout << "7. List Doctors" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, gender, contact, room;
                int age;
                cout << "Enter patient name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter patient age: ";
                cin >> age;
                cout << "Enter patient gender: ";
                cin.ignore();
                getline(cin, gender);
                cout << "Enter patient contact number: ";
                cin.ignore();
                getline(cin, contact);
                cout << "Enter room number: ";
                cin.ignore();
                getline(cin, room);

                Patient patient(name, age, gender, contact, room);
                hospital.addPatient(patient);
                break;
            }
            case 2: {
                hospital.listPatients();
                break;
            }
            case 3: {
                int patientId, doctorId;
                string datetime;
                cout << "Enter patient ID to recommend a doctor: ";
                cin >> patientId;
                cout << "Enter doctor ID to recommend: ";
                cin >> doctorId;
                cout << "Enter appointment date and time (YYYY-MM-DD HH:MM): ";
                cin.ignore();
                getline(cin, datetime);

                struct tm timeInfo = {};
                istringstream iss(datetime);
                iss >> get_time(&timeInfo, "%Y-%m-%d %H:%M");
                if (iss.fail()) {
                    cout << "Invalid date and time format. Please use YYYY-MM-DD HH:MM." << endl;
                    break;
                }
                time_t appointmentTime = mktime(&timeInfo);

                bool patientFound = false;
                for (auto& patient : hospital.getPatients()) {
                    if (patient.patient_id == patientId) {
                        patient.recommendDoctor(doctorId, appointmentTime);
                        cout << "Doctor recommended successfully!" << endl;
                        patientFound = true;
                        break;
                    }
                }
                if (!patientFound) {
                    cout << "Patient not found." << endl;
                }
                break;
            }
            case 4: {
                int patientId;
                string item;
                float cost;
                cout << "Enter patient ID to add a bill: ";
                cin >> patientId;
                cout << "Enter bill item: ";
                cin.ignore();
                getline(cin, item);
                cout << "Enter bill cost: $";
                cin >> cost;

                bool patientFound = false;
                for (auto& patient : hospital.getPatients()) {
                    if (patient.patient_id == patientId) {
                        patient.addBill(item, cost);
                        cout << "Bill added successfully!" << endl;
                        patientFound = true;
                        break;
                    }
                }
                if (!patientFound) {
                    cout << "Patient not found." << endl;
                }
                break;
            }
            case 5: {
                int patientId;
                cout << "Enter patient ID to list bills: ";
                cin >> patientId;

                bool patientFound = false;
                for (const auto& patient : hospital.getPatients()) {
                    if (patient.patient_id == patientId) {
                        patient.listBills();
                        patientFound = true;
                        break;
                    }
                }
                if (!patientFound) {
                    cout << "Patient not found." << endl;
                }
                break;
            }
            case 6: {
                string name, specialization;
                cout << "Enter doctor name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter doctor specialization: ";
                cin.ignore();
                getline(cin, specialization);

                Doctor doctor(name, specialization);
                hospital.addDoctor(doctor);
                break;
            }
            case 7: {
                hospital.listDoctors();
                break;
            }
            case 8: {
                cout << "Exiting the Hospital Management System. Goodbye!" << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please select a valid option." << endl;
            }
        }
    }

    return 0;
}
