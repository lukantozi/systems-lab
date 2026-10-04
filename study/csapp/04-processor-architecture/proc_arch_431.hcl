# CS:APP 3e, Problem 4.31: derive the decode-stage destination
# register in PIPE.

word dstE = [
  D_icode in { IRRMOVQ } && Cnd : D_rB;
  D_icode in { IIRMOVQ, IOPQ } : D_rB;
  D_icode in { IPUSHQ, IPOPQ, ICALL, IRET } : RRSP;
  1 : RNONE; # Don’t write any register
];
