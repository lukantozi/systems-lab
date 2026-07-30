remdiv:
    movq    %rdx, %r8       # copy qp
    movq    %rdi, %rax      # move x to lower 8 bytes of dividend
    cqto                    # sign-extend to upper 8 bytes of dividend
    idivq   %rsi            # divide by y
    movq    %rax, (%r8)     # store quotient at qp
    movq    %rdx, (%rcx)    # store remainder at rp
    ret
