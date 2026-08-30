#include "io.h"
#include <iostream>

int main(void) {
    int x { readNumber() };
    int y { readNumber() };
    writeNumber(x + y);
}
