#include <iostream>

double get_double() {
    std::cout << "Enter a double value: ";
    double num{};
    std::cin >> num;
    return num;
}

char get_operation() {
    std::cout << "Enter +, -, *, or /: ";
    char op{};
    std::cin >> op;
    return op;
}

double get_result(double x, double y, char op) {
    double res{};
    switch (op) {
        case '+':
            res = { x + y };
            break;
        case '-':
            res = { x - y };
            break;
        case '*':
            res = { x * y };
            break;
        case '/':
            res = { x / y };
            break;
    }
    return res;
}

int main() {
    double x   { get_double() };
    double y   { get_double() };
    char   op  { get_operation() };
    double res { get_result(x, y, op) };
    std::cout << x << ' ' << op << ' ' << y << " is " << res << '\n';
}
