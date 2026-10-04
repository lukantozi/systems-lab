# hcl code for signal f_stat, providing the provisional
# status of the fetched instruction

word f_stat = [
  imem_error : SADR;
  !instr_valid : SINS;
  f_icode == IHALT : SHLT;
  1 : SAOK;
]

# only difference to seq code for stat is f_icode
# and the fact that we can't determine if data
# memory will generate error signal for the
# instruction, so we exclude dmem_error
