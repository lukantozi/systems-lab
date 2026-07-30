store_uprod:
    movq    %rsi, %rax      # copy x to multiplicad
    mulq    %rdx            # mult by y
    movq    %rax, (%rdi)    # store lower 8 bytes at dest
    movq    %rdx, 8(%rdi)   # store higher 8 bytes at dest+8
    ret
