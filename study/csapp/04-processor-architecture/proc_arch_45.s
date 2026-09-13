# Modify the Y86-64 code for the sum function (Figure 4.6) to implement a function
# absSum that computes the sum of absolute values of an array. Use a conditional
# jump instruction within your inner loop.

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
