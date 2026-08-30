#include <iostream>

int read_number(int x) {
    std::cout << "Please enter a number: ";
    std::cin >> x;
    return x;
}

void write_answer(int x) {
    std::cout << "The sum is: " << x << '\n';
}

int main(void) {
    int x{};
    read_number(x);
    x = x - read_number(x);
    write_answer(x);
}
