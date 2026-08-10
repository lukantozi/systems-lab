switcher:
    cmpq    $7, %rdi
    ja      .L2
    jmp     *.L4(,%rdi,8)
    .section .rodata
.L7:
    xorq    $15, %rsi
    movq    %rsi, %rdx
.L3:
    leaq    112(%rdx), %rdi
    jmp     .L6
.L5:
    leaq    (%rdx,%rsi), %rdi
    salq    $2, %rdi
    jmp     .L6
.L2:
    movq    %rsi, %rdi
.L6:
    movq    %rdi, (%rcx)
    ret
.L4:
    .quad   .L3
    .quad   .L2
    .quad   .L5
    .quad   .L2
    .quad   .L6
    .quad   .L7
    .quad   .L2
    .quad   .L5
