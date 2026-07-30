uremdiv:
    movq    %rdx, %r8       # copy qp
    movq    %rdi, %rax      # move x to lower 8 bytes of dividend
    movl    $0, %edx        # set upper 8 bytes of dividend to 0
    divq    %rsi            # divide by y (unsigned)
    movq    %rax, (%r8)     # store quotient at qp
    movq    %rdx, (%rcx)    # store remainder at rp
    ret
