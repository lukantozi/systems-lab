test1:
    leaq    12(%rsi), %rbx  # val = y + 12
    testq   %rdi, %rdi      # x < > == 0
    jge     .L2             # if (x < 0)
    movq    %rdi, %rbx      # val = x
    imulq   %rsi, %rbx      # rbx *= y
    movq    %rdi, %rdx      # temp = x
    orq     %rsi, %rdx      # temp |= y
    cmpq    %rsi, %rdi      # x < > == y
    cmovge  %rdx, %rbx      # if (x >= y) val = temp
    ret
.L2:
    idivq   %rsi, %rdi      # else if (x >= 0) val = x / y 
    cmpq    $10, %rsi       # 10 == < > y
    cmovge  %rdi, %rbx      # if (10 >= y) val = x
    ret
