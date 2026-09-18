Fill in the right-hand column of the following table to describe the processing of
the popq instruction on line 7 of the object code in Figure 4.17.

```txt
            Generic                   Specific
Stage       popq rA                   popq %rax
--------------------------------------------------------------------
Fetch       icode : ifun ← M1[PC]     icode : ifun <- M_1[0x02c] = b:0
            rA : rB ← M1[PC + 1]      rA : rB      <- M_1[0x02d] = 0:f
            valP ← PC + 2             valP         <- 0x02c + 2 = 0x02e
--------------------------------------------------------------------
Decode      valA ← R[%rsp]            valA         <- R[%rsp] = 120
            valB ← R[%rsp]            valB         <- R[%rsp] = 120
--------------------------------------------------------------------
Execute     valE ← valB + 8           valE         <- 120 + 8 = 128
--------------------------------------------------------------------
Memory      valM ← M8[valA]           valM         <- M_8[120] = 9
--------------------------------------------------------------------
Write back  R[%rsp] ← valE            R[%rsp]      <- 128
            R[rA] ← valM              R[%rax]      <- 9
--------------------------------------------------------------------
PC update   PC ← valP                 PC           <- 0x02e
--------------------------------------------------------------------
```
