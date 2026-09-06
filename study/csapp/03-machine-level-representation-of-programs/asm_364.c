#define R 7
#define S 5
#define T 13

// R * S * T = 455

long A[R][S][T];

long store_ele(long i, long j, long k, long *dest) {
    *dest = A[i][j][k];
    return sizeof(A);
} /* i in %rdi, j in %rsi, k in %rdx, dest in %rcx */

/** 
 * Extend &D[i][j] = x_D + L(C * i + j) (3.1)
 * L is size of data type T
 *
 * A:
 * &D[i][j][k] = x_D + L(i * (S * T) + j * T + k)
 */

store_ele:
    leaq    (%rsi,%rsi,2), %rax // ret = 3 * j
    leaq    (%rsi,%rax,4), %rax // ret = 4 * ret + j (total of above and this line: ret = j * 13)
    movq    %rdi, %rsi          // j = i
    salq    $6, %rsi            // j << 6 (j = i * 64)
    addq    %rsi, %rdi          // i = i + j (i = i * 65)
    addq    %rax, %rdi          // i = i + ret (i = i * 65 + j * 13)
    addq    %rdi, %rdx          // k = k + i (k = k + i * 65 + j * 13)
    movq    A(,%rdx,8), %rax    // ret = A[k + i * 65 + j * 13]
    movq    %rax, (%rcx)        // *dest = ret
    movl    $3640, %eax         // ret = 3640; ret / sizeof(long) = 455
    ret
