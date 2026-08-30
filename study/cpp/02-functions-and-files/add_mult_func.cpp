#include <iostream>

int add(int x, int y) {
    return x + y;
}

int mult(int x, int y) {
    return x * y;
}

int double_num(int x) {
    return 2 * x;
} 

int main(void) {
    std::cout << add(4, 5) << '\n';
    std::cout << mult(2, add(4, 5)) << '\n';
    std::cout << add(1 + 4, 2 * 5) << '\n';

    int a{5};
    std::cout << add(a, a) << '\n';
    std::cout << add(1, add(2, 3)) << '\n';
}
