;; implementation of switchv (problem 4.50) in Y86
;; using jump table

switchv:
    pushq   %rbp
    rrmovq  %rsp, %rbp
    irmovq  $0, %rax
    subq    %rdi, %rax
    jg      default
    irmovq  $5, %rax
    subq    %rdi, %rax
    jl      default
    rrmovq  %rdi, %rax
    addq    %rax, %rax
    addq    %rax, %rax
    addq    %rax, %rax
    irmovq  .table, %r8
    addq    %rax, %r8
    mrmovq  (%r8), %r8
    pushq   %r8
    ret

case0:
    irmovq  $2730, %rax
    jmp     clean

case25:
    irmovq  $3003, %rax
    jmp     clean

case3:
    irmovq  $3276, %rax
    jmp     clean

default:
	irmovq  $3549, %rax

 clean:
    popq    %rbp
    ret

.table:
    .quad   case0
    .quad   default
    .quad   case25
    .quad   case3
    .quad   default
    .quad   case25
