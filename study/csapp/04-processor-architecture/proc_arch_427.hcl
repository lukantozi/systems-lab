# Write HCL code for Stat

# SAOK -- Status code for normal operation
# SADR -- Status code for address exception
# SINS -- Status code for illegal instruction exception
# SHLT -- Status code for halt

word Stat = [
  1 : SAOK;
  imem_error || dmem_error : SADR;
  !instr_valid : SINS;
  icode == IHALT : SHLT;
]
