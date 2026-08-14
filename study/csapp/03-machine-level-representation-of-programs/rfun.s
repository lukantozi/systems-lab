rfun:
    pushq   %rbx
    movq    %rdi, %rbx
    movl    $0, %eax
    testq   %rdi, %rdi
    je      .L2
    shrq    $2, %rdi
    call    rfun
    addq    %rbx, %rax
.L2:
    popq    %rbx
    ret
