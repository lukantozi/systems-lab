	.file	"main.c"
	.text
	.globl	mult2
	.type	mult2, @function
mult2:
.LFB11:
	.cfi_startproc
	movq	%rdi, %rax
	imulq	%rsi, %rax
	ret
	.cfi_endproc
.LFE11:
	.size	mult2, .-mult2
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"2 * 3 --> %ld\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB12:
	.cfi_startproc
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	movq	%rsp, %rdx
	movl	$3, %esi
	movl	$2, %edi
	call	multstore@PLT
	movq	(%rsp), %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	8(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L5
	movl	$0, %eax
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L5:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE12:
	.size	main, .-main
	.ident	"GCC: (GNU) 16.1.1 20260625"
	.section	.note.GNU-stack,"",@progbits
