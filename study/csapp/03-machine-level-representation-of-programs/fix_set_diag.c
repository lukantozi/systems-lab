#define N 16

typedef int fit_matrix[N][N];

/* A in %rdi, val in %rsi */
void fix_set_diag(fit_matrix A, int val) {
    long i;
    for (i = 0; i < N; i++)
        A[i][i] = val;
}

void fix_set_diag_opt(fit_matrix A, int val) {
    int *i = &A[0][0];
    long end = N * (N + 1);
    do {
        A[i] = val;
        i += N + 1;
    } while (i != end);
}
