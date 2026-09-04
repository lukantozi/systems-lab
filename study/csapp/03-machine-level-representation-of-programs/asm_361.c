long cread(long *xp) {
    return (xp ? *xp :0);
}

long cread_alt(long *xp) {
    long zero = 0
    long *res = &zero;

    if (xp)
        res = xp;

    return *res;
}

int main(void) {
    long i = 10;
    // cread(&i);
    cread_alt(&i);
}
