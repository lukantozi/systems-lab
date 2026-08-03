cond:
    testq   %rdi, %rdi
    je      .L1
    cmpq    %rsi, (%rdi)
    jle     .L1
    movq    %rdi, (%rsi)
.L1:
    rep; ret
