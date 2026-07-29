shift_left4_rightn:
    movq    %rdi, %rax  # get x
    salq    $4, %rax     # x << 4
    movl    %esi, %ecx  # get n (4 bytes)
    sarq    %cl, %rax  # x >>= n
