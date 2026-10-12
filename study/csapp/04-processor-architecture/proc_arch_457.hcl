# load/use hazard
word luh = 
           E_icode in { IMRMOVQ, IPOPQ } &&
           ( E_dstM == d_srcB ||
             ( E_dstM == d_srcA &&
               !(D_icode in { IRMMOVQ, IPUSHQ })
             )
           );

