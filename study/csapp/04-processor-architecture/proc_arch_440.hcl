# E_bubble signal

bool E_bubble = (E_icode in {IMRMOVQ, IPOPQ} && E_dstM in {d srcA, d srcB}) ||
                (E_icode == IJXX && !e_Cnd);
