# OSTEP Ch. 19

source: https://github.com/remzi-arpacidusseau/ostep-homework

## Measurement task (tlb.c):

command ran: ./iter-tlb
pages            | access costs
-----------------|--------------
1 - 8            | ~2-3ns
16 - 65536       | ~5-6ns
131072 - 1048576 | ~11ns


command ran: taskset -c 0 ./iter-tlb (iterations 200; 2000; 20000)
pages            | access costs
-----------------|--------------
1 - 8            | ~2ns
16 - 65536       | ~4-6ns
131072 - 1048576 | ~11ns

Changing from 200 to 20000 didn't change results much. Generally
measurements show stable access cost regions.
