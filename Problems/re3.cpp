#include <iostream>
#include <string>
using namespace std;
bool elements(const string& input) {
    if (input.length() < 3 || input.substr(0, 1) != "a" || input.substr(input.length() - 2, 2) != "de") {
        return false;
    }

    string Sub = input.substr(1, input.length() - 3);
    if (Sub != "" && Sub!= "bc") {
        return false;
    }
    return true;
}
int main() {
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    if (elements(input)) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }
    return 0;
}

