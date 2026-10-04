# if the order of the fifth and sixth cases in the HCL code
# for d_valA were reversed, the following program (Y86-64):

func1:
    irmovq $0x100, %rsp
    irmovq $5, %rdx
    rmmovq rdx, 0(%rsp)
    popq %rsp
    nop
    nop
    rrmovq %rsp, %rax

# would be executed incorrectly: when rrmovq is in decode, popq is
# in write-back, so both W_dstE and W_dstM equal to %rsp and reversing
# fifth and sixth cases prioritizes W_valE (incrementing stack pointer).
# in result, %rax incorrectly receives 0x108 instead of 5
