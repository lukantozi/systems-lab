# The register signal srcB indicates which register should be read to generate the
# signal valB. The desired value is shown as the second step in the decode stage in
# Figures 4.18 to 4.21. Write HCL code for srcB.

word srcB = [
  icode in { IMRMOVQ, IRMMOVQ, IOPQ, IPUSHQ } : rB;
  icode in { IPOPQ, IPUHSQ, IRET, ICALL } : RRSP;
  1 : RNONE; # Don’t need register
];
