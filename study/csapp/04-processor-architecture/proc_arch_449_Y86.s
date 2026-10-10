; snippet below replaces .L5, implementing branch-free
; test from the proc_arch_447_Y86.s using only one
; conditional move.

.L5:
    mrmovq  -24(%rbp), %rax ; i
    addq    %rax
    addq    %rax
    addq    %rax            ; i*8
    mrmovq  -40(%rbp), %r8  ; &dat[i]
    addq    %rax, %r8       ; r8 = dat[i]
    irmovq  $8, %r10
    rrmovq  %r8, %r9
    addq    %r10, %r9       ; r9 = dat[i+1]
    mrmovq  (%r8), %r11
    mrmovq  (%r9), %r12
    rrmovq  %r12, %r14
    subq    %r11, %r14
    cmovge  %r8, %r9
    mrmovq  (%r9), %r12
    rmmovq  %r11, (%r9)
    rmmovq  %r12, (%r8)
