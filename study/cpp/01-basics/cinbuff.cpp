#include <iostream>

int main(void) {
    std::cout << "Enter 4 numbers seperated by any white space: ";

    int x{};
    int y{};
    int z{};
    int t{};
    std::cin >> x;
    std::cin >> y;
    std::cin >> z;
    std::cin >> t;

    std::cout << "You entered " << x << ", " << y << ", " << z << ", " << t << ".\n";
}
