# Write HCL code for the signal mem_data in SEQ.

word mem_addr = [
  # values from register
  icode in { IRMMOVQ, IPUSHQ } : valE;
  # return PC
  icode == ICALL : valP;
];
