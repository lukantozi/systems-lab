struct test {
    short *p;
    struct {
        short x;
        short y;
    } s;
    struct test *next;
}; // total of 20 bytes

/* st in %rdi */
void st_init(struct test *st) {
    st->s.y  = st->s.x;
    st->p    = &(st->s.y);
    st->next = st;
}

/*
 * p   : 0
 * s.x : 8
 * s.y : 10
 * next: 12
 */
