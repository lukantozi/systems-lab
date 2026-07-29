scale3:
    leaq    (%rsi,%rsi,9), %rbx
    leaq    (%rbx,%rdx), %rbx
    leaq    (%rbx,%rdi,%rsi), %rbx
    ret
