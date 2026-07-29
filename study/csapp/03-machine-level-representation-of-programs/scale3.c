/* x in %rdi, y in %rsi, z in %rdx */
short scale3(short x, short y, short z) {
    short t = 10 * y + z + x * z;
    return t;
}
