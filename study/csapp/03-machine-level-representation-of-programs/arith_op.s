arith:
    leaq    15(%rdi), %rbx
    testq   %rdi, %rdi
    cmovns  %rdi, %rbx
    sarq    $4, $rbx
    ret
