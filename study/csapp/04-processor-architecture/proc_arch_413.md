Fill in the right-hand column of the following table to describe the processing of
the irmovq instruction on line 4 of the object code in Figure 4.17:

```txt
            Generic                   Specific
Stage       irmovq V, rB              irmovq $128, %rsp
--------------------------------------------------------------------
Fetch       icode:ifun ← M1[PC]       icode:ifun <- M_1[0x016] = 3:0
            rA:rB ← M1[PC + 1]        rA:rB      <- M_1[0x017] = F:4
            valC ← M8[PC + 2]         valC       <- M_8[0x018] = 128
            valP ← PC + 10            valP       <- 0x020
--------------------------------------------------------------------
Decode
--------------------------------------------------------------------
Execute     valE ← 0 + valC           valE <- 0 + 128 = 128
--------------------------------------------------------------------
Memory
--------------------------------------------------------------------
Write back  R[rB] ← valE              R[%rsp] <- 128
--------------------------------------------------------------------
PC update   PC ← valP                 PC <- 0x020
--------------------------------------------------------------------
```
