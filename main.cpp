#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

// Reads a double value from the user with validation
bool readDouble(const string& prompt, double& out) {
    cout << prompt;
    if (cin >> out) return true; // Success
    // Clear error state and discard invalid input
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid number. Please try again.\n";
    return false;
}

// Reads a valid operator from the user
bool readOperator(char& op) {
    cout << "Enter an operator (+, -, *, /, %, ^): ";
    if (cin >> op) {
        const string valid = "+-*/%^"; // Allowed operators
        if (valid.find(op) != string::npos) return true;
    }
    // Clear invalid input
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid operator. Please try again.\n";
    return false;
}

int main() {
    cout << "=== Calculator Simulator (C++) ===\n"
         << "Supports: +  -  *  /  %  ^\n"
         << "Notes: % is integer modulus; ^ is power.\n\n";

    while (true) {
        double a, b;
        char op;

        // Read the first number
        while (!readDouble("Enter first number: ", a)) {}

        // Read the operator
        while (!readOperator(op)) {}

        // Read the second number
        while (!readDouble("Enter second number: ", b)) {}

        // Perform the calculation
        bool ok = true;
        double result = 0.0;

        switch (op) {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                if (b == 0.0) {
                    cout << "Error: Division by zero!\n";
                    ok = false;
                } else {
                    result = a / b;
                }
                break;
            case '%': {
                // Modulus works for integers only
                long long ai = static_cast<long long>(llround(a));
                long long bi = static_cast<long long>(llround(b));
                if (b == 0.0 || bi == 0) {
                    cout << "Error: Modulo by zero!\n";
                    ok = false;
                } else {
                    result = static_cast<double>(ai % bi);
                }
                break;
            }
            case '^':
                // Power function (a^b)
                result = pow(a, b);
                break;
            default:
                cout << "Unexpected operator.\n";
                ok = false;
        }

        // Show result if operation was successful
        if (ok) {
            cout.setf(ios::fixed);
            cout.precision(6);
            cout << "Result: " << result << "\n";
        }

        // Ask user if they want another calculation
        cout << "\nDo you want another calculation? (y/n): ";
        char cont;
        if (!(cin >> cont) || (cont != 'y' && cont != 'Y')) {
            cout << "Goodbye!\n";
            break;
        }
        cout << "\n";
    }

    return 0;
}
