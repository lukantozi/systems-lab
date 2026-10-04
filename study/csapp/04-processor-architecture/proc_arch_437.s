# combination of mispredicted branch and return in decode
# stage demonstrating mixed control conditions arising

fun1:
    xorq    %rax, %rax
    jne     not_taken
    halt

not_taken:
    ret
