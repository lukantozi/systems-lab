# CS:APP 3e, Problem 4.24: conditionally select the
# register destination for cmovXX.

word dstE = [
  icode in { IRRMOVQ } && Cnd : rB;
  icode in { IIRMOVQ, IOPQ } : rB;
  icode in { IPUSHQ, IPOPQ, ICALL, IRET } : RRSP;
  1 : RNONE; # Don’t write any register
];
