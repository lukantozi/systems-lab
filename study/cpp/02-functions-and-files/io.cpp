#include "io.h"
#include <iostream>

int readNumber() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    return num;
}

void writeNumber(int a) {
    std::cout << "Result: " << a << '\n';
}
