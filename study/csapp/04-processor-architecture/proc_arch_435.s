# hcl code for d_valA using E_dstE instead of e_dstE
# would cause this program to give an incorrect result:

func1:
    irmovq     $2, %rdx
    irmovq     $3, %rbx
    xorq       %rax, %rax
    cmovne     %rdx, %rbx
    rrmovq     %rbx, %rax
    ret

# using E_dstE instead of e_dstE makes d_valA forward
# the failed cmovne's result (2) to rrmovq.
# the cmovne condition is checked, and %rbx remains 3,
# but forwarding ignores that outcome.
# the function therefore returns 2 instead of 3.
