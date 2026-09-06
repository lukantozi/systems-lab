#define M 15

void transpose(long A[M][M]) {
    long i, j;
    for (i = 0; i < M; i++) {
        for (j = 0; j < i; j++) {
            long t = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = t;
        }
    }
}

.L6: /* inner loop */
    movq    (%rdx), %rcx
    movq    (%rax), %rsi
    movq    %rsi, (%rdx)
    movq    %rcx, (%rax)
    addq    $8, %rdx
    addq    $120, %rax
    cmpq    %rdi, %rax
    jne     .L6

/**
 * A. Which register holds a pointer to array element A[i][j]?
 * A: %rdx
 *
 * B. Which register holds a pointer to array element A[j][i]?
 * A: %rax
 *
 * C. What is the value of M?
 * A: 15
 */
