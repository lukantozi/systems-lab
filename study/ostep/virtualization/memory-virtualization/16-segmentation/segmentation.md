# OSTEP Ch. 16

source: https://github.com/remzi-arpacidusseau/ostep-homework

### Simulation tasks (segmentation.py):

1. ./segmentation.py

- -a 128 -p 512 -b 0 -l 20 -B 512 -L 20 -s 0

```
VA  0: 0x0000006c (decimal:  108) --> 0x000001ec -> 492 (seg 1)
VA  1: 0x00000061 (decimal:   97) --> segmentation violation (seg 1)
VA  2: 0x00000035 (decimal:   53) --> segmentation violation (seg 0)
VA  3: 0x00000021 (decimal:   33) --> segmentation violation (seg 0)
VA  4: 0x00000041 (decimal:   65) --> segmentation violation (seg 1)
```

- -a 128 -p 512 -b 0 -l 20 -B 512 -L 20 -s 1
```
VA  0: 0x00000011 (decimal:   17) --> 0x00000011 -> 17 (seg 0)
VA  1: 0x0000006c (decimal:  108) --> 0x000001ec -> 492 (seg 1)
VA  2: 0x00000061 (decimal:   97) --> segmentation violation (seg 1)
VA  3: 0x00000020 (decimal:   32) --> segmentation violation (seg 0)
VA  4: 0x0000003f (decimal:   63) --> segmentation violation (seg 0)
```
- -a 128 -p 512 -b 0 -l 20 -B 512 -L 20 -s 2
```
VA  0: 0x0000007a (decimal:  122) --> 0x00001fa -> 506 (seg 1)
VA  1: 0x00000079 (decimal:  121) --> 0x00001f9 -> 505 (seg 1)
VA  2: 0x00000007 (decimal:    7) --> 0x0000007 -> 7 (seg 0)
VA  3: 0x0000000a (decimal:   10) --> 0x000000a -> 10 (seg 0)
VA  4: 0x0000006a (decimal:  106) --> segmentation violation (seg 1)
```

2. 
  - Highest legal va in segment 0 in above address space is 19
  and in segment 1 it's 127
  - Lowest legal va in segment 1 is 108
  - Highest illegal va in entire address space is 107 and the
    lowest illegal va is 20

  - To confirm my answers, we can run ./segmentation.py -a 128 -p 512 \ 
    -b 0 -l 20 -B 512 -L 20 -A 0,19,20,107,108,127 -c

3. segmentation.py -a 16 -p 128 --b0 ? --l0 ? --b1 ? --l1 ?
   -A 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15

   - For above addresses to get valid, valid, violation, ...,
     violation, valid, valid, I would set following flags:
     --b0 0; --l0 2; --b1 128; --l1 2;

4. To generate a case where roughly 90% of the vas are
   valid, we could make it so that sum of limits is 90%
   of the virtual address space size.

5. To run the simulator so that no virtual addresses are
   valid, we could simply set limit to 0 for each segment.
