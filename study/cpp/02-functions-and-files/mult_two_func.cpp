#include <iostream>

int get_value_from_user() {
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;

    return input;
}

void print_double(int x) {
    std::cout << x << " doubled is: " << x * 2 << '\n';
}

int main(void) {
    print_double(get_value_from_user());
}
