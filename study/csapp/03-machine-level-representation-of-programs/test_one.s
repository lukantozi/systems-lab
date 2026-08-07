test_one:
    movl    $1, %eax
    jmp     .L5
.L6:
    xorq    %rdi, %rax
    shrq    %rdi
.L5:
    testq   %rdi, %rdi
    jne     .L6
    andl    $0, %eax
    ret
