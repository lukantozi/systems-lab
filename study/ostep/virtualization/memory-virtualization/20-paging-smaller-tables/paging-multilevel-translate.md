# OSTEP Ch. 20

source: https://github.com/remzi-arpacidusseau/ostep-homework

## Simulation tasks (pagin-multilevel-translate.py):

1. To locate both, two-level and three-level page tables, we
need just 1 base register. This is due to the fact that, upon
requesting certain address access, hardware only needs to look up
the entry to the first table, after which, if valid, it will refer
to the next table, and if we have three-level page table, to that
one too. Last page table will identify physical page.

2. :||||

page size: 32 bytes
va address space: 1024 pages, 32KB
physical memeory: 128 pages
VA needs 15 bits: 10 (1024) for vpn, 5 for offset
PA needs 12 bits:  7 ( for pfn, 5 for offset
upper 5 bits of va are used to index into a PD

PDE points to page of the page table
each page table has 32 page-table entries
each PTE (if valid) holds the desired va translation 
as PFN

pages 0 - 127

- -s 0


0x611c -> 11000 01000 11100 -> 11000 (0x18, 24); 01000 (0x8, 8); 11100 (0x1c, 28)
        PBDR = 108 (page 108) ->
        83fee0da7fd47febbe9ed5ade4ac90d692d8c1f89fe1ede9 {a1} e8c7c2a9d1dbf
        PE\[24] -> 0xa1 -> 1(v) 0100001 -> page 33 ->
        7f7f7f7f7f7f7f7f {b5} 7f9d7f7f7f7f7f7f7f7f7f7f7f7f7f7f7ff6b17f7f7f7
        PE\[8] -> 0xb5 -> 1(v) 0110101 -> page 53 ->
        0f0c18090e121c0f081713071c1e191b09161b150e030d121c1d0e1a {08} 181100
        PE\[28] -> 0x08


0x3da8 -> 0011110010101000 -> 01111 (0x10, 16); 00101 (0x5, 5); 01000 (0x8, 8)
        PBDR = 108 (page 108) -> entry 16 ->
        83fee0da7fd47febbe9ed5ade4ac90d6 {92} d8c1f89fe1ede9a1e8c7c2a9d1dbf
        PE\[16] -> 0x92 -> 1(v) 0010010 -> page 18 -> entry 5
        7f7f7f7f7f {7f} ab7f7f7f8e7f7f7fdd7f7f7f7f7f7f7f8b7f7f7f7f7f7f7f7f7f
        PE\[5] -> 0x7f -> 0(inv) 111 1111 -> FAULT


0x17f5 -> 00101 (0x5, 5); 11111 (0x1f, 31); 10101 (0x15, 21)
        PBDR = 108 (page) -> entry 5
        83fee0da7f {d4} 7febbe9ed5ade4ac90d692d8c1f89fe1ede9a1e8c7c2a9d1dbf
        PE\[5] = 0xd4 -> 1(v); 1010100 (pfn) -> page 84 -> entry 31
        7f7f7f7f7f7f7f7f7f7f7f7f7f7f7f7f7f7f7f7f7f7f7f7f7f947f7f7f7f7f {ce}
        PE\[31] = 0xce -> 1(v) 1001110 -> page 78 -> entry 21
        0e02171b1c1a1b1c100c1508191a1b121d110d141e {1c} 1802120f131a07160306
        pa -> 78 * 32 + 21 = 0x9d5 -> value -> 0x1c


0x7f6c -> 0111 1111 0110 1100 -> 11111 (0x1f, 31); 11011 (0x1b, 27); 01100 (0xc, 12)
        PBDR = 108 (page) -> entry 31
        83fee0da7fd47febbe9ed5ade4ac90d692d8c1f89fe1ede9a1e8c7c2a9d1db {ff}
        PE\[31] = 0xff -> 1(v) 1111111 (pfn) -> page 127 -> entry 27
        7f7f7f7f7f7f7f7f7f7f7f7f7f7f7f7fdf7f7f7f7f7f7f7f7f7f7f {7f} 7f957f7
        PE\[27] = 0x7f -> 0(inv) -> FAULT


0x0bad -> 0000 1011 1010 1101 -> 00010 (0x2, 2); 11101 (0x1d, 29); 01101 (0xd, 13)
        PBDR = 108 (page) -> entry 2
        83fe {e0} da7fd47febbe9ed5ade4ac90d692d8c1f89fe1ede9a1e8c7c2a9d1dbff
        PE\[2] = 0xe0 -> 1(v) 1100000 (pfn) -> page 96 -> entry 29
        7f7f7f7f7f7f7f7f7f7f7f7f7f7fb67f7f7f7f7f7f7f7f7f7f7f7f7f7f {7f} 7f7f
        PE\[29] = 0x7f -> 0(inv) -> FAULT


0x6d60 -> 11011 (27); 01011 (11); 00000 (0)
        PBDR = 108 (page) -> entry 27
        83fee0da7fd47febbe9ed5ade4ac90d692d8c1f89fe1ede9a1e8c7 {c2} a9d1dbff
        PE\[27] = 0xc2 -> 1(v) 1000010 -> page 66 -> entry 11
        7f7f7f7f7f7f7f7f7f7f7f {7f} 7f7f7f7f7f7f7f7f7f7f7f7f7f7f7f7f7fd77f7f
        inv -> FAULT


0x2a5b -> 01010 (10); 10010 (18); 11011 (27)
        PBDR = 108 (page) -> entry 10
        83fee0da7fd47febbe9e {d5} ade4ac90d692d8c1f89fe1ede9a1e8c7c2a9d1dbff
        PE\[10] = 0xd5 -> 1(v) 1100101 -> page 101 -> entry 18
        0e0a00010b061005061416091a070a16011c {02} 0e1601191e0e030203170c1c0
        PE\[18] = 0x02 -> 0(inv) -> FAULT


0x4c5e -> 10011 (19); 00010 (2); 11110 (30)
        PBDR = 108 (page) -> entry 19
        83fee0da7fd47febbe9ed5ade4ac90d692d8c1 {f8} 9fe1ede9a1e8c7c2a9d1dbff
        PE\[19] = 0xf8 -> 1(v) 1111000 -> page 120 -> entry 2
        7f7f {7f} 7f7f7f7f7f7f7f7f7f7f7f7f7f7f7fcb7f7f7f7f7f7f7f7f7f7f7f7f7
        PE\[2] = 0x7f -> 0(inv) -> FAULT


0x2592 -> 01001 (9); 01100 (12); 10010 (18)
        PBDR = 108 (page) -> entry 9
        83fee0da7fd47febbe {9e} d5ade4ac90d692d8c1f89fe1ede9a1e8c7c2a9d1dbff
        PE\[9] = 0x9e -> 1(v) 0011110 -> page 30 -> entry 12
        7f7f7f7f7f847f7f7f7f977f {bd} 7f7ff47f7f7f7f7f7f7f7f7f7f7f7f7f7f9c7f
        PE\[30] = 0xbd -> 1(v) 0111101 -> page 61 -> entry 18
        010510020c0a0c031c0e1a1e0a0e150d0916 {1b} 1c130b1e1302021701000c100d
        PE\[18 -- (61 * 32 + 18 = 0x7b2)] = 0x1b


0x3e99 -> 01111 (15); 10100 (20); 11001 (25)
        PBDR = 108 (page) -> entry 15
        83fee0da7fd47febbe9ed5ade4ac90 {d6} 92d8c1f89fe1ede9a1e8c7c2a9d1dbff
        PE\[15] = 0xd6 -> 1(v) 1010110 -> page 86 -> entry 20
        7f7f7f7f7f7f7fc57f7f7f7f7f7f7f7f7f7f7f7f {ca} 7f7fee7f7f7f7f7f7f7f7f
        PE\[20] = 0xca -> 1(v) ..... -> page 74 -> entry 25
        0d0b1e08180d0b011a151b0d14030c06011d0604060b10041e {1e} 040c151b0f1c
        PE\[25] = 0x1e at address 32 * 74 + 25
