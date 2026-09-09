    .text
    .globl find_range_cmov
    .type find_range_cmov, @function

find_range_cmov:
    movl    $1, %eax        # default: ZERO
    movl    $2, %ecx        # POS
    movl    $0, %edx        # NEG
    movl    $3, %r8d        # OTHER

    pxor    %xmm1, %xmm1    # %xmm1 = 0.0
    ucomiss %xmm1, %xmm0    # compare x with 0.0

    cmova   %ecx, %eax      # x > 0  → POS
    cmovb   %edx, %eax      # x < 0  → NEG
    cmovp   %r8d, %eax      # unordered / NaN → OTHER
    ret
