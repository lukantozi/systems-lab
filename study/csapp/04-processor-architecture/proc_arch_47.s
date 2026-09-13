# Let us determine the behavior of the instruction pushq %rsp for an x86-64 pro-
# cessor. We could try reading the Intel documentation on this instruction, but a
# simpler approach is to conduct an experiment on an actual machine. The C com-
# piler would not normally generate this instruction, so we must use hand-generated
# assembly code for this task. Here is a test function we have written (Web Aside
# asm:easm on page 214 describes how to write programs that combine C code with
# handwritten assembly code):

    .text
.globl pushtest
pushtest:
    movq    %rsp, %rax      # Copy stack pointer
    pushq   %rsp            # Push stack pointer
    popq    %rdx            # Pop it back
    subq    %rdx, %rax      # Return 0 or 4
    ret

# In our experiments, we find that function pushtest always returns 0. What
# does this imply about the behavior of the instruction pushq %rsp under x86-64?

# Answer:
# It means that pushq instruction pushes original value of %rsp
