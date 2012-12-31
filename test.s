	.file	"test.c"
	.section	.rodata
.LC0:
	.string	"Its an a!"
.LC1:
	.string	"Its a c!"
.LC2:
	.string	"It's an f!!"
.LC3:
	.string	"Tis a d!"
.LC4:
	.string	"huh?"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	movl	12(%ebp), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movzbl	(%eax), %eax
	movb	%al, 31(%esp)
	movsbl	31(%esp), %eax
	subl	$97, %eax
	cmpl	$25, %eax
	ja	.L2
	movl	.L9(,%eax,4), %eax
	jmp	*%eax
	.section	.rodata
	.align 4
	.align 4
.L9:
	.long	.L3
	.long	.L2
	.long	.L4
	.long	.L2
	.long	.L2
	.long	.L2
	.long	.L5
	.long	.L2
	.long	.L2
	.long	.L2
	.long	.L2
	.long	.L2
	.long	.L6
	.long	.L2
	.long	.L2
	.long	.L7
	.long	.L2
	.long	.L2
	.long	.L2
	.long	.L2
	.long	.L2
	.long	.L2
	.long	.L2
	.long	.L2
	.long	.L2
	.long	.L8
	.text
.L3:
	movl	$.LC0, (%esp)
	call	puts
	jmp	.L10
.L4:
	movl	$.LC1, (%esp)
	call	puts
	jmp	.L10
.L5:
	movl	$.LC2, (%esp)
	call	puts
	jmp	.L10
.L6:
	movl	$.LC3, (%esp)
	call	puts
	jmp	.L10
.L7:
	movl	$.LC3, (%esp)
	call	puts
	jmp	.L10
.L8:
	movl	$.LC3, (%esp)
	call	puts
	jmp	.L10
.L2:
	movl	$.LC4, (%esp)
	call	puts
	nop
.L10:
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
