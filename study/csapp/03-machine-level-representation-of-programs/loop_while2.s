loop_while2:
    testq   %rsi, %rsi
    jle     .L8
    movq    %rsi, %rax
.L7:
    imulq   %rdi, %rax
    subq    %rdi, %rsi
    testq   %rsi, %rsi
    jg      .L7
    rep; ret
.L8:
    movq    %rsi, %rax
    ret
