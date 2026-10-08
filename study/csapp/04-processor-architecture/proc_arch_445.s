# implement pushq for any arbitrary REG

my_pushq:
    movq REG, -8(%rsp)
    subq $8, %rsp
