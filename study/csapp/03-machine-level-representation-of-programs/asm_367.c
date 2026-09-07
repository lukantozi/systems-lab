typedef struct {
    long a[2];
    long *p;
} strA;

typedef struct {
    long u[2];
    long q;
} strB;

strB process(strA s) {
    strB r;
    r.u[0] = s.a[1];
    r.u[1] = s.a[0];
    r.q =    *s.p;
    return r;
}

long eval(long x, long y, long z) {
    strA s;
    s.a[0] = x;
    s.a[1] = y;
    s.p = &z;
    strB r = process(s);
    return r.u[0] + r.u[1] + r.q;
} /* x in %rdi, y in %rsi, z in %rdx */

process:
    movq    %rdi, %rax
    movq    24(%rsp), %rdx
    movq    (%rdx), %rdx
    movq    16(%rsp), %rcx
    movq    %rcx, (%rdi)
    movq    8(%rsp), %rcx
    movq    %rcx, 8(%rdi)
    movq    %rdx, 16(%rdi)
    ret

eval:
    subq    $104, %rsp
    movq    %rdx, 24(%rsp)
    leaq    24(%rsp), %rax
    movq    %rdi, (%rsp)
    movq    %rsi, 8(%rsp)
    movq    %rax, 16(%rsp)
    leaq    64(%rsp), %rdi
    call    process
    movq    72(%rsp), %rax
    addq    64(%rsp), %rax
    addq    80(%rsp), %rax
    addq    $104, %rsp
    ret

/*
    A. We can see on line 2 of function eval that it allocates 104 bytes on the stack.
    Diagram the stack frame for eval, showing the values that it stores on the
    stack prior to calling process.

    Answer: 0(%rsp) = s.a[0] = x
            8(%rsp) = s.a[1] = y
           16(%rsp) = s.p    = &z
           24(%rsp) = z

    B. What value does eval pass in its call to process?

    Answer: eval passes the structure value s to process on the stack:
            s.a[0] at 0(%rsp)
            s.a[1] at 8(%rsp)
            s.p    at 16(%rsp)

            It additionally passes &r in %rdi so process has somewhere to write
            its 24-byte return value.

    C. How does the code for process access the elements of structure argument s?

    Answer: process accesses the structure argument s through its stack-frame
            offsets: 8(%rsp), 16(%rsp), 24(%rsp)

    D. How does the code for process set the fields of result structure r?

    Answer: process writes the fields of r through the pointer in %rdi

    E. Complete your diagram of the stack frame for eval, showing how eval
    accesses the elements of structure r following the return from process.

    Answer: after process returns, eval acesses r this way:
            movq 72(%rsp), %rax
            addq 64(%rsp), %rax
            addq 80(%rsp), %rax

            %rax = x + y + z

    F. What general principles can you discern about how structure values are
    passed as function arguments and how they are returned as function results?

    Answer: - Small structures may be passed and returned using registers.
            - A structure too large for register passing is passed by value
              on the stack.
*/

