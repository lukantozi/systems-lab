#include "input.h"
#include <iostream>

int get_integer() {
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
    return x;
}
