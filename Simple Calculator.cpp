#include <iostream>

int main() {
    double num1, num2;
    char op;

    std::cout << "=== Simple Calculator ===\n";
    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter an operator (+, -, *, /): ";
    std::cin >> op;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    // Perform operation based on input
    switch(op) {
        case '+':
            std::cout << "Result: " << num1 + num2 << "\n";
            break;
        case '-':
            std::cout << "Result: " << num1 - num2 << "\n";
            break;
        case '*':
            std::cout << "Result: " << num1 * num2 << "\n";
            break;
        case '/':
            if (num2 != 0)
                std::cout << "Result: " << num1 / num2 << "\n";
            else
                std::cout << "Error: Division by zero is not allowed.\n";
            break;
        default:
            std::cout << "Invalid operator!\n";
    }

    return 0;
}
