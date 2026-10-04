if third and fourth cases in the HCL code for d_valA were reversed,
resulting behaviour of last instruction for the following program:

```asm
    irmovq $5, %rdx
    irmovq $0x100,%rsp
    rmmovq %rdx,0(%rsp)
    popq %rsp
    rrmovq %rsp,%rax
```

instead of having 5 in %rax, it would receive
0x108.
