-> Combinational logic (300ps) -> Reg (20ps)
delay = 320ps
Throughput = 3.12 GIPS

divide comb logic into k pipeline stages, each having delay of 20ps

A. thoughput(k) = (1 / ((300/k) + 20)) * 1000 = 1000k/(300 + 20k)
   delay(k) = ((300/k) + 20)k = 300 + 20k

B. k->inf:
        delay -> inf
        throughput -> 1000 / 20 = 50
