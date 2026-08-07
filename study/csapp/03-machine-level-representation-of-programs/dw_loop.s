# Annotated CS:APP Practice Problem 3.23 listing, reproduced verbatim.
# It is presented as compiler-generated code, but the printed exercise and
# solution are internally inconsistent with the supplied C source.
# This is a study note, not a buildable assembly implementation.

dw_loop:
    movq    %rdi, %rbx          # move x in %rbx
    movq    %rdi, %rcx          # move x in %rcx (y)
    idivq   $9, %rcx            # y = x / 9
    leaq    (,%rdi,4), %rdx     # n(%rdx) = 4 * x(%rdi)
.L2:
    leaq    5(%rbx,%rcx), %rcx  # y += x + 5, per book's annotation
    subq    $2, %rdx            # n -= 2
    testq   %rdx, %rdx          # n > < == 0
    jg      .L2                 # if n > 0, loop
    rep; ret
