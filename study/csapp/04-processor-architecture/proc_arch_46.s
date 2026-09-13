# Modify the Y86-64 code for the sum function (Figure 4.6) to implement a function
# absSum that computes the sum of absolute values of an array. Use a conditional
# move instruction within your inner loop.

# long sum(long *start, long count)
# start in %rdi, count in %rsi
sum:
    irmovq  $8,%r8         # Constant 8
    irmovq  $1,%r9         # Constant 1
    xorq    %rax,%rax      # sum = 0
    andq    %rsi,%rsi      # Set CC
    jmp     test           # Goto test
loop:
    mrmovq  (%rdi),%r10    # Get *start
    xorq    %r11,%r11
    subq    %r10,%r11      # check if negative
    cvmovg  %r11,%r10
    addq    %r10,%rax      # Add to sum
    addq    %r8,%rdi       # start++
    subq    %r9,%rsi       # count--. Set CC
test:
    jne     loop           # Stop when 0
    ret                    # Return
