/* x in %rdi */
test_two:
    movl    $64, %edx
    movl    $0, %eax
.L10:
    movq    %rdi, %rcx
    andl    $1, %ecx
    addq    %rax, %rax
    orq     %rcx, %rax
    shrq    %rdi
    subq    $1, %rdx
    jne     .L10
    rep; ret
