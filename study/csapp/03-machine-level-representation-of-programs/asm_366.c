#define NR(n) (3 * (n))
#define NC(n) (4 * (n) + 1)

long sum_col(long n, long A[NR(n)][NC(n)], long j) {
    long i;
    long result = 0;
    for (i = 0; i < NR(n); i++)
        result += A[i][j];
    return result;
} /* n in %rdi, A in %rsi, j in %rdx */

sum_col:
    leaq    1(,%rdi,4), %r8     // %r8 = 4 * n + 1
    leaq    (%rdi,%rdi,2), %rax // %rax = 3 * n (NR(n))
    movq    %rax, %rdi          // %rdi  = 3 * n
    testq   %rax, %rax          // pre-loop check; can't have 0 < NR(n)
    jle     .L4
    salq    $3, %r8             // %r8 *= 8; %r8 = 8 * (4 * n + 1)
    leaq    (%rsi,%rdx,8), %rcx // %rcx = 8 * j + A;
    movl    $0, %eax
    movl    $0, %edx
.L3:
    addq    (%rcx), %rax        // %rax += A[i][j]
    addq    $1, %rdx            // i++
    addq    %r8, %rcx           // %rcx = (8 * j + A) + (4 * n + 1)
    cmpq    %rdi, %rdx          // i < NR(n)
    jne     .L3
    rep;    ret
.L4:
    movl    $0, %eax            // result = 0
    ret
