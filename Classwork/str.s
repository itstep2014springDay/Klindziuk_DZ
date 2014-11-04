	.file	"str.c"
	.section	.rodata
.LC0:
	.string	"mama"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	$.LC0, -8(%rbp)
	movq	$1634558317, -32(%rbp)
	movw	$0, -24(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	puts
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	puts
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.9.1 20140903 (prerelease)"
	.section	.note.GNU-stack,"",@progbits
