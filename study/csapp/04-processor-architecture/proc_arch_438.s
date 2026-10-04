# combination of load/use hazard and return in decode
# stage demonstrating mixed control conditions arising

fun1:
    irmovq 0x200, %rsp
    call fun2
    halt

fun2:
    irmovq 0x100, %rbx
    mrmovq 0(%rbx), %rsp
    ret

    .pos 0x100
    .quad 0x1f8
