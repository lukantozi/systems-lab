struct ACE {
    short      v;
    struct ACE *p;
};

/* ptr in %rdi */
short test(struct ACE *ptr) {
    short val = 1;
    while (ptr != NULL) {
        val *= ptr->v;
        ptr = ptr->p;
    }
    return val;
}
