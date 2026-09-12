# For each byte sequence listed, determine the Y86-64 instruction sequence it en-
# codes. If there is some invalid byte in the sequence, show the instruction sequence
# up to that point and indicate where the invalid value occurs. For each sequence,
# we show the starting address, then a colon, and then the byte sequence.

# A. 0x100: 30f3fcffffffffffffff40630008000000000000
instr_A:
    0x100: 30f3fcffffffffffffff | irmovq    $-4, %rbx 
    0x10a: 40630008000000000000 | rmmovq    %rsi, 0x800(%rbx)

# B. 0x200: a06f800c020000000000000030f30a00000000000000
instr_B:
    0x200: a06f                 | pushq     %rsi
    0x202: 800c02000000000000   | call      0x020c
    0x20b: 00                   | halt
    0x20c: 30f30a00000000000000 | irmovq    $10, %rbx

# C. 0x300: 5054070000000000000010f0b01f
instr_C:
    0x300: 50540700000000000000 | mrmovq   7(%rsp), %rbp
    0x30a: 10                   | nop
    0x30b: f0                   | 0xf0 # invalid instruction
    0x30c: b01f                 | popq      %rcx

# D. 0x400: 611373000400000000000000
instr_D:
    0x400: 6113                 | subq     %rcx, %rbx
    0x402: 730004000000000000   | je       instr_D # 0x400
    0x40c: 00                   | halt

# E. 0x500: 63 62 a0f0
instr_E:
    0x500: 6362                 | xorq     %rsi, %rdx
    0x502: a0                   | 0xa0 # pushq instruction
    0x503: f0                   | 0xf0 # invalid register
