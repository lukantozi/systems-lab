tlb: tlb.c
	gcc -O0 tlb.c -o tlb

.PHONY: run pin

run: tlb
	./iter-tlb

pin: tlb
	taskset -c 0 ./iter-tlb
