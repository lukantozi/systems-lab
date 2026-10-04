# CS:APP 3e, Problem 4.21: select the destination register
# for memory results.

word dstM = [
  icode in { IMRMOVQ, IPOPQ } : rA;
  1 : RNONE; # Don’t write any register
];
