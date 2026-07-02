int x = 0;
atomic_int y = 0;

thread1() {
    x = 2;
    y = 3;            // sync on write
}

thread2() {
    while (y != 3) {} // sync on read
    prinf("x is now %d\n", x); // 2
}
