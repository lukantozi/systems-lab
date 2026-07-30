arith3:
    orq     %rsi, %rdx
    sarq    $9, %rdx
    notq    %rdx
    movq    %rsi, %rax
    subq    %rdx, %rax
    ret
