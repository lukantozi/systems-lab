st_init:
    movl    8(%rdi), %eax
    movl    %eax, 10(%rdi)
    leaq    10(%rdi), %rax
    movq    %rax, (%rdi)
    movq    %rdi, 12(%rdi)
    ret
