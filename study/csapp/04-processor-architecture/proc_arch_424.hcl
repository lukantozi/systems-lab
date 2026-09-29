# Modify the HCL code for dstE to implement cmovXX, having
# instruction code IRRMOVQ, by making use of the Cnd signal.

word dstE = [
  icode in { IRRMOVQ } && Cnd : rB;
  icode in { IIRMOVQ, IOPQ } : rB;
  icode in { IPUSHQ, IPOPQ, ICALL, IRET } : RRSP;
  1 : RNONE; # Don’t write any register
];
