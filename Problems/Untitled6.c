#include <iostream>
#include <string>

bool isValidString(const std::string& input) {
    if (input.length() < 2 || input.substr(0, 1) != "a" || input.substr(input.length() - 2, 2) != "de") {
        return false;
    }

    int i = 1;
    int len = input.length();
    while (i < len - 2) {
        if (input.substr(i, 2) != "bc") {
            return false;
        }
        i += 2;
    }

    return true;
}

int main() {
    std::string input;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    if (isValidString(input)) {
        std::cout << "Valid string" << std::endl;
    } else {
        std::cout << "Invalid string" << std::endl;
    }

    return 0;
}
