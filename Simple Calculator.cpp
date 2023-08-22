#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char operation;

    cout << "Welcome to the Advanced Calculator!" << endl;
    cout << "Enter the first number: ";
    cin >> num1;

    // Clear the input buffer
    while (cin.get() != '\n');

    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    cout << "Enter the second number: ";
    cin >> num2;

    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
                return 1;
            }
            break;
        default:
            cout << "Error: Invalid operation." << endl;
            return 1;
    }

    // Display the result with a calculator-style format
    cout << "\n";
    cout << "     " << num1 << " " << operation << " " << num2 << " = " << result << "\n";
    cout << "  -----------------------" << endl;

    return 0;
}

