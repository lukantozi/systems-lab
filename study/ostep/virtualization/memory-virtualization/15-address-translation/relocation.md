# OSTEP Ch. 15

source: https://github.com/remzi-arpacidusseau/ostep-homework

### Simulation tasks (relocation.py):

1. ./relocation.py

with -s 1:

ARG address space size 1k
ARG phys mem size 16k

Base   : 0x0000363c (decimal 13884)
Limit  : 290

Virtual Address Trace
  VA  0: 0x0000030e (decimal:  782) --> SEGMENTATION VIOLATION
  VA  1: 0x00000105 (decimal:  261) --> VALID: 0x00003741
  VA  2: 0x000001fb (decimal:  507) --> SEGMENTATION VIOLATION
  VA  3: 0x000001cc (decimal:  460) --> SEGMENTATION VIOLATION 
  VA  4: 0x0000029b (decimal:  667) --> SEGMENTATION VIOLATION 

***
with -s 2

ARG address space size 1k
ARG phys mem size 16k

Base   : 0x00003ca9 (decimal 15529)
Limit  : 500

Virtual Address Trace
  VA  0: 0x00000039 (decimal:   57) --> 0x00003ce2
  VA  1: 0x00000056 (decimal:   86) --> 0x00003cff 
  VA  2: 0x00000357 (decimal:  855) --> SEGMENTATION VIOLATION
  VA  3: 0x000002f1 (decimal:  753) --> SEGMENTATION VIOLATION
  VA  4: 0x000002ad (decimal:  685) --> SEGMENTATION VIOLATION 

***
with -s 3

Base   : 0x000022d4 (decimal 8916)
Limit  : 316

Virtual Address Trace
  VA  0: 0x0000017a (decimal:  378) --> SEGMENTATION VIOLATION
  VA  1: 0x0000026a (decimal:  618) --> SEGMENTATION VIOLATION 
  VA  2: 0x00000280 (decimal:  640) --> SEGMENTATION VIOLATION 
  VA  3: 0x00000043 (decimal:   67) --> 0x00002317
  VA  4: 0x0000000d (decimal:   13) --> 0x000022e1

***
    
2. To ensure that after running ./relocation.py -s 0 -n 10,
   all generated virtual addresses are within bounds, we need
   to set -l 930 as bounds register (limit).

3. ./relocation.py -s 1 -n 10 -l 100 
   Maximum value that base can be set to, such that the address
   space still fits into physical memory is 1024 * 16 - 99 = 16285

4. Larger address and physical-memory sizes do not change the
   translation rule: an address is valid when VA < limit, and
   its physical address is base + VA.

5. For uniformly generated virtual addresses from 0 through A − 1,
   the expected valid fraction is limit / A, for limits between 0
   and A. The expected graph is linear; finite samples fluctuate
   around it.
