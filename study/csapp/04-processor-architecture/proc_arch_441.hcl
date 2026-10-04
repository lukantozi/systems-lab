# signal set_cc

bool set_cc = E_icode == IOPQ &&
              !W_stat in {SADR, SINS, SHLT} &&
              !m_stat in {SADR, SINS, SHLT};
