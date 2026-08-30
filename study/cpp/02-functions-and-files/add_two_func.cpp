#include <iostream>

int get_value_from_user() {
    std::cout << "Enter an integet: ";
    int input{};
    std::cin >> input;

    return input;
}

int main(void) {
    int x { get_value_from_user() };
    int y { get_value_from_user() };

    std::cout << x << " + " << y << " = " << x + y << '\n';
}
