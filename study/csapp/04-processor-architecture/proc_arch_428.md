-> A (80ps) -> B (30ps) -> C (60ps) -> D (50ps) -> E (70ps) -> F (10ps) -> Reg (20ps)

A. best reg placement -- between C and D. throughput -> 5.26; latency -> 380ps
B. best 2 reg placement -- between B and C and between D and E. throughput -> 7.69; latency -> 390
C. A (80) -> reg -> B (30) -> reg -> C (60) -> reg -> D (50) -> reg -> E+F (80) -> reg.
    max throughput of 10; latency -> 500; 5 stages
