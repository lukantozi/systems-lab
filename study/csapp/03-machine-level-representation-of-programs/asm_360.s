loop:
    movl    %esi, %ecx  # n in rcx - ecx - cl
    movl    $1, %edx    # mask = 1
    movl    $0, %eax    # result = 0
    jmp     .L2         # loop
.L3:
    movq    %rdi, %r8   # x in r8
    andq    %rdx, %r8   # x & mask
    orq     %r8, %rax   # result |= mask
    salq    %cl, %rdx   # mask << n
.L2:
    testq    %rdx, %rdx
    jne      .L3
    rep;     ret
