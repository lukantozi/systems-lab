simplefun_a:
    vmovsd .LC1(%rip), %xmm1
    vandpd %xmm1, %xmm0, %xmm0
.LC1:
    .long 4294967295 # FFFFFFFF
    .long 2147483647 # 7FFFFFFF
    .long 0
    .long 0

simplefun_b:
    vxorpd %xmm0, %xmm0, %xmm0

simplefun_c:
    vmovsd .LC2(%rip), %xmm1
    vxorpd %xmm1, %xmm0, %xmm0
.LC2:
    .long 0
    .long -2147483648 # 80000000
    .long 0
    .long 0
