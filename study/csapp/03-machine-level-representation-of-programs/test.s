test:
    leaq    (%rdx,%rsi), %rax
    subq    %rdi, %rax
    cmpq    $5, %rdx
    jle     .L2
    cmpq    $2, %rsi
    jle     .L3
    movq    %rdi, %rax
    idivq   %rdx, %rax
    ret
.L3:
    movq    %rdi, %rax
    idivq   %rsi, %rax
    ret
.L2:
    cmpq    $3, %rdx
    jge     .L4
    movq    %rdx, %rax
    idivq   %rsi, %rax
.L4:
    rep; ret
