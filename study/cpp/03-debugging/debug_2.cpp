#include <iostream>

int read_number() {
    std::cout << "Please enter a number: ";
    int x{};
    std::cin >> x;
    return x;
}

void write_answer(int x) {
    std::cout << "The quotient is: " << x << '\n';
}

int main(void) {
    int x{ read_number() };
    int y{ read_number() };
    write_answer(x/y);
}
