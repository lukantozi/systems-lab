# Write HCL code for the signal mem_write in SEQ.

bool mem_write = icode in { IRMMOVQ, IPUSHQ, ICALL };
