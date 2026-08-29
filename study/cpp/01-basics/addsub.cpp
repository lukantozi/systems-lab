#include <iostream>

int main(void) {
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    int y{};
    std::cout << "Enter another integer: ";
    std::cin >> y;

    std::cout << x << " + " << y << " is " << x + y << ".\n";
    std::cout << x << " - " << y << " is " << x - y << ".\n";
}
