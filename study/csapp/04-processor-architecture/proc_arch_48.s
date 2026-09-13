# The following assembly-code function lets us determine the behavior of the in-
# struction popq %rsp for x86-64:

    .text
.globl poptest
poptest:
    movq    %rsp, %rdi      # Save stack pointer
    pushq   $0xabcd         # Push test value
    popq    %rsp            # Pop to stack pointer
    movq    %rsp, %rax      # Set popped value as return value
    movq    %rdi, %rsp      # Restore stack pointer
    ret

# We find this function always returns 0xabcd. What does this imply about the
# behavior of popq %rsp? What other Y86-64 instruction would have the exact same
# behavior?

# Answer: it sets %rsp to the value read from memory.
#         equivalent instruction would be: mrmovq (%rsp), %rsp
