; implementation of branch-free test and swap
; snippet below is from the proc_arch_447_Y86.s
; bubble sort implementation .L5. rest of the
; code is unchanged

.L5:
    mrmovq      -24(%rbp), %rax
    addq        %rbx, %rax
    rrmovq      %rax, %r9 ; (1) leaq instr start
    addq        %r9, %r9
    addq        %r9, %r9
    addq        %r9, %r9
    rrmovq      %r9, %rdx ; leaq end
    mrmovq      -24(%rbp), %rax
    rrmovq      %rax, %r9 ; (2) leaq instr start
    addq        %r9, %r9
    addq        %r9, %r9
    addq        %r9, %r9
    rrmovq      %r9, %rcx ; leaq end
    mrmovq      -40(%rbp), %rax
    addq        %rdx, %rax
    mrmovq      (%rax), %rdx
    mrmovq      -40(%rbp), %rax
    addq        %rcx, %rax
    mrmovq      (%rax), %rax
    subq        %rax, %rdx
    mrmovq      -24(%rbp), %rax
    addq        %rbx, %rax
    rrmovq      %rax, %r9 ; (3) leaq instr start
    addq        %r9, %r9
    addq        %r9, %r9
    addq        %r9, %r9
    rrmovq      %r9, %rdx ; leaq end
    mrmovq      -40(%rbp), %rax
    addq        %rdx, %rax
    mrmovq      (%rax), %rax
    rmmovq      %rax, -8(%rbp) ; t = %rax (i + 1)
    mrmovq      -24(%rbp), %rax
    rrmovq      %rax, %r9 ; (4) leaq instr start
    addq        %r9, %r9
    addq        %r9, %r9
    addq        %r9, %r9
    rrmovq      %r9, %rdx ; leaq end - r
    mrmovq      -40(%rbp), %rax
    addq        %rdx, %rax
    mrmovq      -24(%rbp), %rdx
    addq        %rbx, %rdx
    rrmovq      %rdx, %r9 ; (5) leaq start
    addq        %r9, %r9
    addq        %r9, %r9
    addq        %r9, %r9
    rrmovq      %r9, %rcx ; leaq end
    mrmovq      -40(%rbp), %rdx
    addq        %rcx, %rdx
    mrmovq      (%rax), %r12
    mrmovq      (%rax), %rax ; data[i]: rax = 9
    mrmovq      (%rdx), %r13
    rrmovq      %r13, %r14
    subq        %r12, %r14
    cmovge      %r13, %rax
    rmmovq      %rax, (%rdx) ; data[i+1] = 9
    mrmovq      -24(%rbp), %rax
    rrmovq      %rax, %r9 ; (6) leaq start
    addq        %r9, %r9
    addq        %r9, %r9
    addq        %r9, %r9
    rrmovq      %r9, %rdx ; leaq end
    mrmovq      -40(%rbp), %rax
    addq        %rax, %rdx
    mrmovq      -8(%rbp), %rax ; rax = t = 3
    rrmovq      %r13, %r14
    subq        %r12, %r14
    cmovge      %r12, %rax
    rmmovq      %rax, (%rdx)   ; data[i] = 3
