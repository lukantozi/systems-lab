sum_element:
    leaq    0(,%rdi,8), %rdx
    subq    %rdi, %rdx
    addq    %rsi, %rdx
    leaq    (%rsi,%rsi,4), %rax
    addq    %rax, %rdi
    movq    Q(,%rdi,8), %rax
    addq    P(,%rdx,8), %rax
    ret
