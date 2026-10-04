# CS:APP 3e, Problem 4.20: select the second source register in SEQ.

word srcB = [
  icode in { IMRMOVQ, IRMMOVQ, IOPQ, IPUSHQ } : rB;
  icode in { IPOPQ, IPUHSQ, IRET, ICALL } : RRSP;
  1 : RNONE; # Don’t need register
];
