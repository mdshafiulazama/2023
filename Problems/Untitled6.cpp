
#include <iostream>
#include <string>
using namespace std;
int elements(const string& input) {
    if (input.length() < 2 || input.substr(0, 1) != "a" || input.substr(input.length() - 2, 2) != "de") {
        return 0;
    }
    size_t index = 1;
    while (index < input.length() - 2) {
        if (input.substr(index, 2) != "bc") {
            return 0;
        }
        index += 2;
    }
    return 1;
}
int main() {
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    int Valid = elements(input);
    if (Valid) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }

    return 0;
}
