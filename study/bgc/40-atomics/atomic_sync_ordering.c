int x, y, z = 0;
atomic_int a = 0;

thread1() {
    x = 10;
    y = 20;
    a = 999; // release
    z = 30;
}

thread2() {
    while (a != 999) {} // acquire

    assert(x == 10); // never asserts, x is always 10
    assert(y == 20); // never asserts, y is always 20
    assert(z == 30); // might assert!!!
                     // reordering in thread1 may cause 
                     // z = 30 to go before a = 999
}
