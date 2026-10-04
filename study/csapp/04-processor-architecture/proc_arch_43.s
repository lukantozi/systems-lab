 # CS:APP 3e, Problem 4.3: adapt the supplied sum routine to use iaddq
 
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
