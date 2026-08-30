#include "input.h"
#include <iostream>

int main(void) {
    int x{ get_integer() };
    int y{ get_integer() };

    std::cout << x << " + " << y << " is " << x + y << '\n';
}
