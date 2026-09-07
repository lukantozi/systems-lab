#define A 9
#define B 5

typedef struct {
    int x[A][B]; /* 176 < 4AB <= 184 -> 44 < AB <= 46  */
    long y;
} str1;

typedef struct {
    char array[B]; // 5 <= B <= 8
    int t;
    short s[A]; // A <= 10
    long u;
} str2;

void setVal(str1 *p, str2 *q) {
    long v1 = q->t;
    long v2 = q->u;
    p->y = v1+v2;
} /* p in %rdi, q in %rsi */

setVal:
    movslq  8(%rsi), %rax
    addq    32(%rsi), %rax
    movq    %rax, 184(%rdi)
    ret
