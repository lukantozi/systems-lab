    .text
    .globl      find_range_branch
    .type       find_range_branch, @function

find_range_branch:
    pxor         %xmm1, %xmm1    # %xmm1 = 0.0
    ucomiss      %xmm1, %xmm0    # compare x (%xmm0) with 0.0

    jp           .Lother         # PF=1: unordered, i.e. x is NaN
    jb           .Lneg           # CF=1: x < 0
    je           .Lzero          # ZF=1: x == 0

    movl         $2, %eax        # x > 0: POS
    ret

.Lneg:
    movl         $0, %eax        # NEG
    ret

.Lzero:
    movl         $1, %eax        # ZERO
    ret

.Lother:
    movl         $3, %eax        # OTHER
    ret
