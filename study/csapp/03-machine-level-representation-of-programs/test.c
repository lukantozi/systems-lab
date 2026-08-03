/* x in %rdi, y in %rsi, z in %rdx */
short test(short x, short y, short z) {
    short val = z + y - x;
    if (val > 5) {
        if (z > 2)
            val = x / z;
        else
            val = x / y;
    } else if (val < 3)
        val = z / y;
    return val;
}
