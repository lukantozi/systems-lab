# implement popq for any arbitrary REG

my_popq:
    addq $8, %rsp
    movq -8(%rsp), REG
