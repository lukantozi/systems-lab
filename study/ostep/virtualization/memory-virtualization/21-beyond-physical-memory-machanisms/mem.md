# OSTEP Ch. 21

source: https://github.com/remzi-arpacidusseau/ostep-homework

## Measurement tasks (mem.c):

1. when running ./mem 1, us column in geos up to 6 from 0.
after running second ./mem 1 in another terminal, it doubled
and we get 13 in the us column. when running 3 instancees of
./mem 1, we can observe us of 19, essentially triple the amount
of one instance running, which seems intuitive.

2. running ./mem 1024, we can observe free column of the
running vmstat 1 command getting almost instantly reduced
by ~1024mb (1051120b extra), while in my case, swapd value doesn't
change at all. killing running ./mem 1024 instance also instantly
recovers free memory (1046040b extra).

observing closer second time i get results below, tracking only changes
values of free column as i run and terminate ./mem 1024:

run ./mem 1024 -> 25010904 -> 25010680 -> 23959572 ->
23959080 -> 23959052 -> 23958840 -> 23958592 -> kill ./mem 1024 ->
25006008 -> 25005756 -> 25005788 -> 25010340 -> 25010136 -> 25009864 ->
25009136 -> 25008232 -> 25008092

so = pages written to swap, si = pages read back from swap.
3. having a device with 32118560 kb, ./mem 15000 doesn't
change values in si and so.
- ./mem 16000 - 24000 -- no change

- ./mem 25000 - first signs of swpd: 152-144

- ./mem 26000 - 28000 -- swpd 144

- ./mem 29000 - so -- 188

- running again ./mem 28000, no si so, but swpd remains nonzero
since pages remain in swap until touched 

- ./mem 30000 - so: 1008, 116, 0, 0, 0 , 1860, 796, 512

- ./mem 31000 - so: starting to take out a lot more values now,
and after terminating the process, si values appear, meaning that
si after termination comes from other processes faulting their evicted pages back in

- ./mem 32000 - both si and so are observable while the process
runs. so values are higher, so the program's pages are written
to swap and read back. After the process exits, si still appears
because other processes fault their evicted pages back in.

4. running same experiments as above, nothing much changes for single running
instnace of the ./mem program with any argument i've supplied.
bo keeps displaying values as i run ./mem, higher values as we provide larger arguments
consistent with swap writes (so).

5. running ./mem
- 15000:
    - loop 0 in 2340.92 ms
    - loop 1 in 1832.50 ms
    - loop 2 in 1836.84 ms
    - loop 3 in 1835.69 ms
    - loop 4 in 1832.74 ms

- 20000:
    - loop 0 in 3080.07 ms
    - loop 1 in 2432.15 ms
    - loop 2 in 2438.82 ms
    - loop 3 in 2444.11 ms

- 25000:
    - loop 0 in 3815.43 ms
    - loop 1 in 3038.16 ms
    - loop 2 in 3040.01 ms
    - loop 3 in 3051.57 ms

- 30000:
    - loop 0 in 5404.23 ms
    - loop 1 in 4941.12 ms
    - loop 2 in 7776.20 ms
    - loop 3 in 4441.33 ms
    - loop 4 in 4060.47 ms
    - loop 5 in 3701.53 ms
    - loop 6 in 3757.21 ms
    - loop 7 in 3715.44 ms
    - loop 8 in 3693.00 ms
    - loop 9 in 3694.03 ms

6. ./mem 40000:
much higher values of si now. system is running too slow. memory allocation
fails at 72326 (72325 ok); swapfile of size 40gb.
