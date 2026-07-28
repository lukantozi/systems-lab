decode1:
    movq    (%rdi), %r8  
    movq    (%rsi), %rcx 
    movq    (%rdx), %rax 
    movq    %r8, (%rsi)     # *yp = *xp;
    movq    %rcx, (%rdx)    # *zp = *yp;
    movq    %rax, (%rdi)    # *xp = *zp;
    ret
