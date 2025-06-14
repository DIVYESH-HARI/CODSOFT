#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char op;
    double result;

    cout << "=====================" << endl;
    cout << "   Simple Calculator " << endl;
    cout << "=====================" << endl;

    // Get first number
    cout << "Enter the first number: ";
    cin >> num1;

    // Get operator
    cout << "Choose an operation (+, -, *, /): ";
    cin >> op;

    // Get second number
    cout << "Enter the second number: ";
    cin >> num2;

    // Perform the selected operation
    switch(op) {
        case '+':
            result = num1 + num2;
            cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
            } else {
                cout << "Error: Division by zero is not allowed!" << endl;
            }
            break;
        default:
            cout << "Invalid operation. Please use +, -, *, or /." << endl;
    }

    return 0;
}
0