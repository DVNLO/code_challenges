	.file	"inplace.c"
	.text
	.p2align 4
	.globl	spherical_to_cartesian_3f
	.type	spherical_to_cartesian_3f, @function
spherical_to_cartesian_3f:
.LFB23:
	.cfi_startproc
	endbr64
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	subq	$88, %rsp
	.cfi_def_cfa_offset 112
	leaq	44(%rsp), %rbp
	leaq	40(%rsp), %r12
	movq	%xmm0, 48(%rsp)
	movss	48(%rsp), %xmm0
	movq	%r12, %rsi
	movq	%rbp, %rdi
	movss	%xmm1, 56(%rsp)
	call	sincosf@PLT
	movss	44(%rsp), %xmm2
	movq	%r12, %rsi
	movq	%rbp, %rdi
	movss	40(%rsp), %xmm3
	movss	52(%rsp), %xmm0
	movss	%xmm2, 12(%rsp)
	movss	%xmm3, 8(%rsp)
	call	sincosf@PLT
	movss	56(%rsp), %xmm1
	movss	12(%rsp), %xmm2
	mulss	%xmm1, %xmm2
	mulss	8(%rsp), %xmm1
	movaps	%xmm2, %xmm0
	mulss	40(%rsp), %xmm2
	mulss	44(%rsp), %xmm0
	movss	%xmm2, 68(%rsp)
	movss	%xmm0, 72(%rsp)
	movq	68(%rsp), %xmm0
	addq	$88, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE23:
	.size	spherical_to_cartesian_3f, .-spherical_to_cartesian_3f
	.p2align 4
	.globl	transform
	.type	transform, @function
transform:
.LFB24:
	.cfi_startproc
	endbr64
	testq	%rdx, %rdx
	je	.L12
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	leaq	(%rdx,%rdx,2), %rax
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	leaq	(%rsi,%rax,4), %r13
	movq	%rcx, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	movq	%rdi, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movq	%rsi, %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	.p2align 4,,10
	.p2align 3
.L6:
	movq	0(%rbp), %xmm0
	movss	8(%rbp), %xmm1
	addq	$12, %rbx
	addq	$12, %rbp
	call	*%r12
	movq	%xmm0, -12(%rbx)
	movss	%xmm1, -4(%rbx)
	cmpq	%r13, %rbx
	jne	.L6
	addq	$8, %rsp
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L12:
	.cfi_restore 3
	.cfi_restore 6
	.cfi_restore 12
	.cfi_restore 13
	ret
	.cfi_endproc
.LFE24:
	.size	transform, .-transform
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"sizeof(spherical_coord_f) == %lu\n"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"coord_count == %lu\n"
.LC3:
	.string	"delta_t == %f\n"
.LC5:
	.string	"iters per second == %lu\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB25:
	.cfi_startproc
	endbr64
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	movl	$12, %edx
	leaq	.LC0(%rip), %rsi
	xorl	%eax, %eax
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	movl	$1, %edi
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	subq	$32, %rsp
	.cfi_def_cfa_offset 80
	call	__printf_chk@PLT
	movl	$1, %edi
	xorl	%eax, %eax
	movl	$2147483648, %edx
	leaq	.LC1(%rip), %rsi
	call	__printf_chk@PLT
	movabsq	$25769803776, %rdi
	call	malloc@PLT
	testq	%rax, %rax
	je	.L20
	movq	%rax, %rbx
	leaq	28(%rsp), %r12
	leaq	24(%rsp), %rbp
	movabsq	$25769803776, %r14
	call	clock@PLT
	addq	%rbx, %r14
	movq	%rax, %r13
	.p2align 4,,10
	.p2align 3
.L17:
	movss	(%rbx), %xmm0
	movq	%rbp, %rsi
	movq	%r12, %rdi
	addq	$12, %rbx
	call	sincosf@PLT
	movss	-8(%rbx), %xmm0
	movq	%rbp, %rsi
	movq	%r12, %rdi
	movss	28(%rsp), %xmm1
	movss	24(%rsp), %xmm3
	movss	%xmm1, 20(%rsp)
	movss	%xmm3, 8(%rsp)
	call	sincosf@PLT
	movss	-4(%rbx), %xmm2
	movss	20(%rsp), %xmm1
	mulss	%xmm2, %xmm1
	movaps	%xmm1, %xmm0
	mulss	24(%rsp), %xmm1
	movss	%xmm1, -12(%rbx)
	mulss	28(%rsp), %xmm0
	movss	%xmm0, -8(%rbx)
	movss	8(%rsp), %xmm0
	mulss	%xmm2, %xmm0
	movss	%xmm0, -4(%rbx)
	cmpq	%rbx, %r14
	jne	.L17
	call	clock@PLT
	pxor	%xmm0, %xmm0
	movl	$1, %edi
	leaq	.LC3(%rip), %rsi
	subq	%r13, %rax
	cvtsi2sdq	%rax, %xmm0
	movl	$1, %eax
	divsd	.LC2(%rip), %xmm0
	movsd	%xmm0, 8(%rsp)
	call	__printf_chk@PLT
	movsd	.LC4(%rip), %xmm1
	movsd	8(%rsp), %xmm0
	comisd	%xmm1, %xmm0
	jnb	.L18
	cvttsd2siq	%xmm0, %rcx
.L19:
	movl	$2147483648, %eax
	xorl	%edx, %edx
	movl	$1, %edi
	divq	%rcx
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdx
	xorl	%eax, %eax
	call	__printf_chk@PLT
	xorl	%eax, %eax
.L15:
	addq	$32, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 48
	popq	%rbx
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
.L18:
	.cfi_restore_state
	subsd	%xmm1, %xmm0
	cvttsd2siq	%xmm0, %rcx
	btcq	$63, %rcx
	jmp	.L19
.L20:
	movl	$1, %eax
	jmp	.L15
	.cfi_endproc
.LFE25:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC2:
	.long	0
	.long	1093567616
	.align 8
.LC4:
	.long	0
	.long	1138753536
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
