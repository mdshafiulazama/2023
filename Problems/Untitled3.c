#include <iostream>
#include <cstring>
using namespace std;

void MainMenu();

void AuthenticateUser() {
    system("cls");
    char userId[10];
    char password[20];

    cout << "\n\n\t\t\t\tEnter User ID: ";
    cin >> userId;

    cout << "\n\n\t\t\t\tEnter Password: ";
    cin >> password;

    if (strcmp(userId, "1234") == 0 && strcmp(password, "saikot") == 0) {
        cout << "\n\n\t\t\t\tAuthentication Successful!";
        cout << "\n\n\t\t\t\tPress any key to continue...";
        cin.ignore();
        cin.get();
        MainMenu();
    } else {
        cout << "\n\n\t\t\t\tAuthentication Failed!";
        cout << "\n\n\t\t\t\tPress any key to continue...";
        cin.ignore();
        cin.get();
        AuthenticateUser();
    }
}

void MainMenu() {
    system("cls");
    // Display main menu options
    cout << "\n\n\t\t\t\tMain Menu";
    // Rest of the menu code goes here
}

int main() {
    AuthenticateUser();
    return 0;
}
