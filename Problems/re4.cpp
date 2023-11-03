#include <iostream>
#include <string>
using namespace std;
bool elements(const string& input) {
    for (char ch : input) {
        if (ch < 'a' || ch > 'm') {
            return false;
        }
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
