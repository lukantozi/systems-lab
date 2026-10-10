iaddq in Y86 (combination of addq and irmovq):

Fetch:
    icode : ifun <- M1[PC]
    rA : rB      <- M1[PC + 1]
    valC         <- M8[PC + 2]
    valP         <- PC + 10

Decode: valB <- R[rB]

Execute:
    valE <- valB + valC
    Set CC

Memory: No operation

Write back: R[rB] <- valE

PC update: PC <- valP
