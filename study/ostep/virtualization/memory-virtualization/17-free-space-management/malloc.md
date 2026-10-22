# OSTEP Ch. 17

source: https://github.com/remzi-arpacidusseau/ostep-homework

### Simulation tasks (malloc.py):

1. ./malloc.py -n 10 -H 0 -p BEST -s 0

Size 100; baseAddr 1000; headerSize 0; alignment -1
policy BEST; listOrder ADDRSORT; coalesce False

```sh
ptr[0] = Alloc(3) returned 1000 (searched 1 element)
Free List [ Size 1 ]: [ addr:1003 sz:97 ]

Free(ptr[0]) returned 0
Free List [ Size 2 ]: [ addr:1000 sz:3 ] [ addr:1003 sz:97 ]

ptr[1] = Alloc(5) returned 1003 (searched 2 elements)
Free List [ Size 2 ]: [ addr:1000 sz:3 ] [ addr:1008 sz:92 ]

Free(ptr[1]) returned 0
Free List [ Size 3 ]: [ addr:1000 sz:3 ] [ addr:1003 sz:5] [ addr:1008 sz:92 ]

ptr[2] = Alloc(8) returned 1008 (searched 3 elements)
Free List [ Size 3 ]: [ addr:1000 sz:3 ] [ addr:1003 sz:5] [ addr:1016 sz:84 ]

Free(ptr[2]) returned 0
Free List [ Size 4 ]: [ addr:1000 sz:3 ] [ addr:1003 sz:5] [ addr:1008 sz:8 ] [ addr:1016 sz:84 ]

ptr[3] = Alloc(8) returned 1008 (searched 4 elements)
Free List [ Size 3 ]: [ addr:1000 sz:3 ] [ addr:1003 sz:5] [ addr:1016 sz:84 ]

Free(ptr[3]) returned 0
Free List [ Size 4 ]: [ addr:1000 sz:3 ] [ addr:1003 sz:5] [ addr:1008 sz:8 ] [ addr:1016 sz:84 ]

ptr[4] = Alloc(2) returned 1000 (searched 4 elements)
Free List [ Size 4 ]: [ addr:1002 sz:1 ] [ addr:1003 sz:5] [ addr:1008 sz:8 ] [ addr:1016 sz:84 ]

ptr[5] = Alloc(7) returned 1008
Free List [ Size 4 ]: [ addr:1002 sz:1 ] [ addr:1003 sz:5] [ addr:1015 sz:1 ] [ addr:1016 sz:84 ]
```

Over time free list is growing in number, giving us more fragmented
free memory.

2. ./malloc.py -n 10 -H 0 -p WORST -s 0 

After running the simulation with WORST, we get more
chunks in free list compared to when run with BEST.

3. ./malloc.py -n 10 -H 0 -p FIRST -s 0

Using FIRST fit reduces the overhead of searching through
all the elements of the free list.

4. -l ADDRSORT, -l SIZESORT+, -l SIZESORT-

Running the simulation with above options doesn't change
much when using BEST/WORST fit algorithms, since the entire list
has to be trasversed for these to work. When it comes to FIRST
fit algorithm, SIZESORT- accumulates more elements in free list
at the end, while SIZESORT+ has no significant effect in this
particular case.

5. When generating 1000 random allocations, without coalescing,
   at the end we get free list size of 30 and 50 at the end when
   running with BEST and FIRST fit algorithms. With coalesc flag
   turned on, we get free lists size of 1 in both cases.

   It also seems like that even with -C on, SIZESORT- gives similarly
   large number of elements in free list (~100), SIZESOT+ (~30) smaller than -,
   but larger than addrsort (1). So, even with coalescing on, order matters.

6. ./malloc.py -n 1000 -H 0 -p FIRST -s 0 -P x -c
    x = 50; gives size 50
    x = 70; gives size 54
    x = 80; size 46
    x = 80; size 14
    x = 90; size 3
    x = 95; size 1
    x = 99; size 0
    x = 30; size 47
    x = 20; size 42
    x = 10; size 43
    x =  5; size 27
    x =  1; size 30

7. ./malloc.py -b 0 -S 100 -A +10,+10,+10,+10,+10,+10,+10,+10,+10,+10,-1,-3,-5,-7,-9
