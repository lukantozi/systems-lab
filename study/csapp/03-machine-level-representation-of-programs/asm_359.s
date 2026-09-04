store_prod:
    movq    %rdx, %rax
    cqto
    movq    %rsi, %rcx
    sarq    $63, %rcx
    imulq   %rax, %rcx
    imulq   %rsi, %rdx
    addq    %rdx, %rcx
    mulq    %rsi      
    addq    %rcx, %rdx
    movq    %rax, (%rdi)
    movq    %rdx, 8(%rdi)
    ret
