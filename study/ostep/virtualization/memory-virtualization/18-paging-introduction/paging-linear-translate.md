# OSTEP Ch. 18

source: https://github.com/remzi-arpacidusseau/ostep-homework

### Simulation tasks (paging-linear-translate.py):

1. Calculating sizes of linear page tables as the size of
the address space changes:

- -P 1k -a 1m -p 512m -v -n 0
A: 1024

- -P 1k -a 2m -p 512m -v -n 0
A: 2048

- -P 1k -a 4m -p 512m -v -n 0
A: 4096

2. Calculating sizes of linear page tables as the size of
the page size changes:

- -P 2k -a 1m -p 512m -v -n 0
A: 512

- -P 4k -a 1m -p 512m -v -n 0
A: 256

3. Performing translations with following arguments:

- -P 1k -a 16k -p 32k -v -u 0
A: All the addresses are invalid. -u 0 allocates 0%
valid addresses.

- -P 1k -a 16k -p 32k -v -u 25
  - [       0]  0x80000018
  - [       1]  0x00000000 - x
  - [       2]  0x00000000 - x
  - [       3]  0x00000000 - x
  - [       4]  0x00000000 - x
  - [       5]  0x80000009
  - [       6]  0x00000000 - x
  - [       7]  0x00000000 - x
  - [       8]  0x80000010
  - [       9]  0x00000000 - x
  - [      10]  0x80000013
  - [      11]  0x00000000 - x
  - [      12]  0x8000001f
  - [      13]  0x8000001c
  - [      14]  0x00000000 - x
  - [      15]  0x00000000 - x

16 1K pages, 4 bits to represent PN, and 10 bits to represent
the offset.

VA 0x00003986 (decimal:    14726) --> invalid address
- 0x3986 -> 3 -> 0011; VPN = 11 10 (14); offset = 01 1000 0110

VA 0x00002bc6 (decimal:    11206) --> (PE\[13] << 10) + offset -> 0001 0011 111100 0110 -> 0x4fc6 -> 20422
- 0x2bc6 -> 2 -> 0010; VPN = 10 10 (10); offset = 11 1100 0110 

VA 0x00001e37 (decimal:     7735) --> invalid address (key = 7)
- 0x1e37 -> 1 -> 0001; VPN = 01 11 (7);

VA 0x00000671 (decimal:     1649) --> invalid address (key = 1)
- 0x0671 -> 0 -> 0000; VPN = 00 01 (1); offset = 10 0111 0001

VA 0x00001bc9 (decimal:     7113) --> invalid address
- 0x1bc9 -> 1 -> 0001; VPN = 01 10 (6); offset = 11 1100 1001


- -P 1k -a 16k -p 32k -v -u 50
  - [       0]  0x80000018
  - [       1]  0x00000000
  - [       2]  0x00000000
  - [       3]  0x8000000c
  - [       4]  0x80000009
  - [       5]  0x00000000
  - [       6]  0x8000001d
  - [       7]  0x80000013
  - [       8]  0x00000000
  - [       9]  0x8000001f
  - [      10]  0x8000001c
  - [      11]  0x00000000
  - [      12]  0x8000000f
  - [      13]  0x00000000
  - [      14]  0x00000000
  - [      15]  0x80000008

4 bit vpn, 10 bit offset

VA 0x00003385 (decimal:    13189) --> (entry 12) << 10 + offset = 0000 1111 1110 0001 01 -> 0x3f85
- 0x3385 -> 3 -> 0011; VPN = 11 00 (12); offset = 11 1000 0101

VA 0x0000231d (decimal:     8989) --> invalid address entry 8 -> seg fault)
- 0x231d -> 2 -> 0010; VPN = 10 00  (8); offset = 10 0001 1101

VA 0x000000e6 (decimal:      230) -->  PE\[0] << 10 + offset = 00 0110 0000 1110 0110
- 0x00e6 -> 0 -> 0000; VPN = 00 00  (0); offset = 00 1110 0110

VA 0x00002e0f (decimal:    11791) --> invalid address
- 0x2e0f -> 2 -> 0010; VPN = 10 11 (11); offset = 10 0000 1111

VA 0x00001986 (decimal:     6534) --> 0001 1101 01 1000 0110 -> 0x7586
- 0x1986 -> 1 -> 0001; VPN = 01 10  (6); offset = 01 1000 0110

As the percentage of allocation of the valid addresses increases
we get more valid mappings for more virtual pages.

4. More translations:

***
- -P 8 -a 32 -p 1024 -v -s 1
ARG address space size 32; ARG phys mem size 1024; ARG page size 8
ARG verbose True; ARG addresses -1


Page Table (from entry 0 down to the max size)
  - [       0]  0x00000000
  - [       1]  0x80000061
  - [       2]  0x00000000
  - [       3]  0x00000000

Having address space size of 32, and page size of 8 we get 4 pages
with total of 5 bit representation out of which, first 2 represent VPN,
and the rest 3 offset.

VA 0x0000000e (decimal:       14) --> (0x61 << 3) + 0x6 = 782 -> 0x30e
- 0x0e -> 0 -> 000 0; VPN = 01 (1); offset = 110;

VA 0x00000014 (decimal:       20) --> invalid address (entry 2)
- 0x14 -> 1 -> 000 1; VPN = 10 (2); offset = 100;

VA 0x00000019 (decimal:       25) --> invalid address
- 0x19 -> 1 -> 000 1; VPN = 11 (3); offset = 001;

VA 0x00000003 (decimal:        3) --> invalid address
- 0x03 -> 0 -> 000 0; VPN = 00 (0)

VA 0x00000000 (decimal:        0) --> invalid address
- 0x00 -> 0 -> 000 0; VPN = 00 (0)

***
- -P 8k -a 32k -p 1m -v -s 2
ARG seed 2; ARG address space size 32k
ARG phys mem size 1m; ARG page size 8k
ARG verbose True; ARG addresses -1

Page Table (from entry 0 down to the max size)
  - [       0]  0x80000079
  - [       1]  0x00000000
  - [       2]  0x00000000
  - [       3]  0x8000005e

Address space size 32k and page size 8k give us total of 4 pages,
32k is rerpresented with 15 bits, first two giving us VPN, and rest offset

VA 0x000055b9 (decimal:    21945) --> invalid
- 0x55b9 -> 5 -> 0 10 1; VPN = 10 (2)

VA 0x00002771 (decimal:    10097) --> invalid
- 0x2771 -> 2 -> 0 01 0; VPN = 01 (1)

VA 0x00004d8f (decimal:    19855) --> invalid
- 0x4d8f -> 4 -> 0 10 0; VPN = 10 (2)

VA 0x00004dab (decimal:    19883) --> invalid
- 0x4dab -> 4 -> VPN = 10 (2)

VA 0x00004a64 (decimal:    19044) --> invalid
- 0x4a64 -> VPN = 10 (2)

5. -P 1k -a 64k -p 32k -n 0

If we for some reason allocate size of virtual address space greater than or
equal to physical memory size, the simulator will reject it and throw an error.
