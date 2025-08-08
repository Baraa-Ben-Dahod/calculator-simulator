# Calculator Simulator (C++)

A simple command-line calculator program written in C++ as a beginner-friendly project.  
This program allows the user to perform basic arithmetic operations, including additional features for better usability.

## Features
- Addition (`+`)
- Subtraction (`-`)
- Multiplication (`*`)
- Division (`/`) with zero-division handling
- Integer modulus (`%`) — works with rounded integer values
- Power (`^`) using the `pow` function
- Input validation for numbers and operators
- Continuous calculations without restarting the program
- Simple and clear text-based interface

## How to Compile and Run

### Compile:
```bash
g++ main.cpp -o calculator
```

### Run:
```bash
./calculator
```

## Example Usage
```
=== Calculator Simulator (C++) ===
Supports: +  -  *  /  %  ^
Notes: % is integer modulus; ^ is power.

Enter first number: 10
Enter an operator (+, -, *, /, %, ^): ^
Enter second number: 3
Result: 1000.000000

Do you want another calculation? (y/n): y

Enter first number: 9
Enter an operator (+, -, *, /, %, ^): %
Enter second number: 4
Result: 1.000000
```

## Requirements
- C++ compiler (e.g., g++, clang++)
- Works on Windows, Linux, and macOS

## Future Improvements
- Support more mathematical operations (square root, factorial, trigonometric functions, etc.)
- Allow complex expressions with multiple operators and precedence rules
- Create a graphical user interface (GUI) version
- Implement unit tests for validation

## Author
Created by **Baraa Ben Dahod** as part of personal learning projects.
