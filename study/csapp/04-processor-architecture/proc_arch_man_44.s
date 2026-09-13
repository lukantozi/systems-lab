# Write Y86-64 code to implement a recursive product function rproduct, based
# on the following C code:

# long rproduct(long *start, long count)
# {
#   if (count <= 1)
#       return 1;
#   return *start * rproduct(start+1, count-1);
# }

# Use the same argument passing and register saving conventions as x86-64 code
# does. You might find it helpful to compile the C code on an x86-64 machine and
# then translate the instructions to Y86-64.

rproduct:
    pushq   %rbp
    rrmovq  %rsp, %rbp
    pushq   %rbx
    irmovq  $24, %r8
    subq    %r8, %rsp
    rmmovq  %rdi, -24(%rbp)
    rmmovq  %rsi, -32(%rbp)
    irmovq  $1, %r8
    mrmovq  -32(%rbp), %r9
    subq    %r8, %r9
    rmmovq  %r9, -32(%rbp)
    jg  .L2
    irmovq  $1, %rax
    jmp .L3
.L2:
    mrmovq  -24(%rbp), %rax
    mrmovq  (%rax), %rbx
    mrmovq  -32(%rbp), %rax
    rrmovq  %rax, %rdx # leaq
    mrmovq  -24(%rbp), %rax
    irmovq  $8, %r8
    addq    %r8, %rax
    rrmovq  %rdx, %rsi
    rrmovq  %rax, %rdi
    call    rproduct
    rrmovq  %rax, %r10 # counter = recursive result
    irmovq  $0, %rax   # accumulator = 0
    irmovq  $1, %r11   # decrement = 1
mult:
    andq    %r10, %r10 # set condition
    jle .L3            # <= 0, complete
    addq    %rbx, %rax # accum += *start
    subq    %r11, %r10 # counter--
    jmp     mult
.L3:
    mrmovq  -8(%rbp), %rbx
    rrmovq  %rbp, %rsp
    popq    %rbp
    ret
