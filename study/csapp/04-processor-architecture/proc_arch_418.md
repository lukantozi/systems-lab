Fill in the right-hand column of the following table to describe the processing of
the call instruction on line 9 of the object code in Figure 4.17:

```txt
            Generic                 Specific 
Stage       call Dest               call 0x041
--------------------------------------------------------------------
Fetch       icode : ifun ← M1[PC]   icode : ifun <- M_1[0x037] = 8:0
            valC ← M8[PC + 1]       valC <- M_8[0x038] = 0x041
            valP ← PC + 9           valP <- 0x037 + 9 = 0x040
--------------------------------------------------------------------
Decode
            valB ← R[%rsp]          valB <- 128
--------------------------------------------------------------------
Execute     valE ← valB + (−8)      valE <- 128 + (-8) = 120
--------------------------------------------------------------------
Memory      M8[valE] ← valP         M_8[120] <- 0x040
--------------------------------------------------------------------
Write back  R[%rsp] ← valE          R[%rsp] <- 120
--------------------------------------------------------------------
PC update   PC ← valC               PC <- 0x041
--------------------------------------------------------------------
```
