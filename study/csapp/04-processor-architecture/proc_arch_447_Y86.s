bubble_b:
    pushq   %rbp
    rrmovq  %rsp, %rbp
    rmmovq  %rdi, -40(%rbp)
    rrmovq  %rsi, %rax
    irmovq  $1, %rbx
    subq    %rbx, %rax      ; count-1
    rmmovq  %rax, -16(%rbp) ; last = count-1
    jmp .L2
.L6:
    irmovq  $0, %r8
    rmmovq  %r8, -24(%rbp)
    jmp .L3
.L5:
    mrmovq  -24(%rbp), %rax
    addq    %rbx, %rax
    irmovq  $7, %r8
    rrmovq  %rax, %r9
scale1: ; leaq instr start
    addq    %rax, %r9
    subq    %rbx, %r8
    jne     scale1
    rrmovq  %r9, %rdx ; leaq end
    mrmovq  -24(%rbp), %rax
    irmovq  $7, %r8
    rrmovq  %rax, %r9
scale2: ; leaq instr start
    addq    %rax, %r9
    subq    %rbx, %r8
    jne     scale2
    rrmovq  %r9, %rcx ; leaq end
    mrmovq  -40(%rbp), %rax
    addq    %rdx, %rax
    mrmovq  (%rax), %rdx
    mrmovq  -40(%rbp), %rax
    addq    %rcx, %rax
    mrmovq  (%rax), %rax
    subq    %rax, %rdx
    jge     .L4
    mrmovq  -24(%rbp), %rax
    addq    %rbx, %rax
    irmovq  $7, %r8
    rrmovq  %rax, %r9
scale3:
    addq    %rax, %r9
    subq    %rbx, %r8
    jne     scale3
    rrmovq  %r9, %rdx ; leaq end
    mrmovq  -40(%rbp), %rax
    addq    %rdx, %rax
    mrmovq  (%rax), %rax
    rmmovq  %rax, -8(%rbp)
    mrmovq  -24(%rbp), %rax
    irmovq  $7, %r8
    rrmovq  %rax, %r9
scale4:
    addq    %rax, %r9
    subq    %rbx, %r8
    jne     scale4
    rrmovq  %r9, %rdx ; leaq end
    mrmovq  -40(%rbp), %rax
    addq    %rdx, %rax
    mrmovq  -24(%rbp), %rdx
    addq    %rbx, %rdx
    irmovq  $7, %r8
    rrmovq  %rdx, %r9
scale5:
    addq    %rdx, %r9
    subq    %rbx, %r8
    jne     scale5
    rrmovq  %r9, %rcx ; leaq end
    mrmovq  -40(%rbp), %rdx
    addq    %rcx, %rdx
    mrmovq  (%rax), %rax
    rmmovq  %rax, (%rdx)
    mrmovq  -24(%rbp), %rax
    irmovq  $7, %r8
    rrmovq  %rax, %r9
scale6:
    addq    %rax, %r9
    subq    %rbx, %r8
    jne     scale6
    rrmovq  %r9, %rdx ; leaq end
    mrmovq  -40(%rbp), %rax
    addq    %rax, %rdx
    mrmovq  -8(%rbp), %rax
    rmmovq  %rax, (%rdx)
.L4:
    mrmovq  -24(%rbp), %r8
    addq    %rbx, %r8
    rmmovq   %r8, -24(%rbp)
.L3:
    mrmovq  -24(%rbp), %rax
    mrmovq  -16(%rbp), %r8
    subq    %r8, %rax
    jl      .L5
    mrmovq  -16(%rbp), %r8
    subq    %rbx, %r8
    rmmovq  %r8, -16(%rbp)
.L2:
    mrmovq  -16(%rbp), %r11
    irmovq  $0, %r10
    subq    %r10, %r11
    jg      .L6
    nop
    nop
    popq    %rbp
    ret
