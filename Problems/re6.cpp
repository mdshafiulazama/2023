#include <iostream>
#include <string>

using namespace std;

bool isValidString(const string& input) {
    if (input.length() != 6) {
        return false;
    }

    for (char ch : input) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return false;
        }
    }

    return true;
}

int main() {
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    if (isValidString(input)) {
        cout << "Valid string" << endl;
    } else {
        cout << "Invalid string" << endl;
    }

    return 0;
}
