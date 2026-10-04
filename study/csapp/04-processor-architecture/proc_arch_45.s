# CS:APP 3e, Problem 4.5: adapt the supplied sum routine for
# absolute values using a conditional jump.

sum:
    irmovq  $8, %r8
    irmovq  $1, %r9
    xorq    %rax, %rax         # sum = 0
    andq    %rsi,%rsi          # Set CC
    jmp test
loop:
    mrmovq (%rdi),%r10         # Get *start
    andq    %r10, %r10
    jl  neg
    addq    %r10,%rax          # Add to sum
    addq    %r8,%rdi           # start++
    subq    %r9,%rsi           # count--. Set CC
    jg  loop                   # Stop when 0
    ret
neg:
    subq    %r10,%rax          # if negative, subtract
    addq    %r8,%rdi           # start++
    subq    %r9,%rsi           # count--. Set CC
    jg  loop                   # Stop when 0
    ret
test:
    jne loop
    ret
