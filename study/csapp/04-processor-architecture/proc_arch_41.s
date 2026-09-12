# Determine the byte encoding of the Y86-64 instruction sequence that follows. The
# line .pos 0x100 indicates that the starting address of the object code should be
# 0x100.

.pos 0x100 # Start code at address 0x100
    irmovq      $15,%rbx        # 0x100: 30 f3 0f 00 00 00 00 00 00 00
    rrmovq      %rbx,%rcx       # 0x10a: 20 31
loop:                           # 0x10c: 0x10c
    rmmovq      %rcx,-3(%rbx)   # 0x10c: 20 13 fd ff ff ff ff ff ff ff
    addq        %rbx,%rcx       # 0x116: 60 31
    jmp         loop            # 0x118: 70 0c 01 00 00 00 00 00 00
