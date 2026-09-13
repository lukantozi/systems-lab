# One common pattern in machine-level programs is to add a constant value to a
# register. With the Y86-64 instructions presented thus far, this requires first using an
# irmovq instruction to set a register to the constant, and then an addq instruction to
# add this value to the destination register. Suppose we want to add a new instruction
# iaddq with the following format:
 
# Byte         0       1        2                                      9
# iaddq V, rB  | C | 0 | F | rB |                      V                        |

# This instruction adds the constant value V to register rB.
# Rewrite the Y86-64 sum function of Figure 4.6 to make use of the iaddq
# instruction. In the original version, we dedicated registers %r8 and %r9 to hold
# constant values. Now, we can avoid using those registers altogether.

# long sum(long *start, long count)
# start in %rdi, count in %rsi
sum:
    xorq %rax, %rax      # sum = 0
    andq %rsi,%rsi       # Set CC
    jmp test
loop:
    mrmovq (%rdi),%r10   # Get *start
    addq %r10,%rax       # Add to sum
    iaddq 1,%rdi         # start++
    iaddq -1,%rsi        # count--. Set CC
test:
    jne sum              # Stop when 0
    ret
