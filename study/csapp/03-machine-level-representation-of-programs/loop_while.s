loop_while:
    movl    $0, %eax
    jmp     .L2
.L3:
    leaq    (,%rsi,%rdi), %rdx
    addq    %rdx, %rax
    subq    $1, %rdi
.L2:
    cmpq    %rsi, %rdi
    jg      .L3
    rep; ret
