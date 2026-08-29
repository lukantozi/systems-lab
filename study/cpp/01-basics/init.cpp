#include <iostream>

int main() {
    int width { 5 };
    std::cout << width << '\n';

    int a; // default intializaition (no initializer)

    // traditional initialization forms
    int b = 5;      // copy-initialization (initial value after equals sign)
    int c ( 6 );    // direct-initialization (initial value in parentheses)

    // modern initialization forms (preferred)
    int d { 7 };    // direct-list-init (init value in braces)
    int e {};       // value-init (empty braces)
}
