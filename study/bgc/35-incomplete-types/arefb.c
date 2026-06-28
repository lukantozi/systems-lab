struct a {
    struct b *x; // refers to a `struct b`
};

struct b {
    struct a *x; // refers to a `struct a`
};
