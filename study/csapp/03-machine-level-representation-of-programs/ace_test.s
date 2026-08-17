test:
    movl    $1, %eax
    jmp     .L2
.L3:
    imulq   (%rdi), %rax
    movq    2(%rdi), %rdi
.L2:
    testq   %rdi, %rdi
    jne     .L3
    rep; ret
