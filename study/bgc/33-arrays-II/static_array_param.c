/* compiler assumes we pass in an
array of no less than 4 elements */
int func(int p[static 4]) {
    return *p;
}

int main(void) {
    int a[] = {11, 22, 33, 44};
    int b[] = {11, 22, 33, 44, 55};
    int c[] = {11, 22};

    func(a); // ok
    func(b); // ok
    func(c); // ub: 4 c is under 4 elements
}
