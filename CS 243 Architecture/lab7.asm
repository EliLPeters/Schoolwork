.data
welcm:	.asciiz	"Welcome, please enter your value:\n"
answr:	.asciiz	"The sum is: "

.text
main:
la	$a0,	welcm
li	$v0,	4
syscall
li	$v0,	5
syscall
add	$a0,	$v0,	$0
jal	gauss
add	$s0,	$v0,	$0
la	$a0,	answr
li	$v0,	4
syscall
add	$a0,	$s0,	$0
li	$v0,	1
syscall
li	$v0,	10
syscall


funct:
add	$v0,	$0,	$0
add	$t0,	$0,	$0
loop:
slt	$t1,	$t0,	$a0
beq	$t1,	$0,	retrn
add	$v0,	$v0,	$t0
addi	$t0,	$t0,	1
j	loop
retrn:
jr	$ra

funct2:
add	$v0,	$0,	$0
add	$t0,	$0,	$0
loop2:
add	$v0,	$v0,	$t0
addi	$t0,	$t0,	1
#slt	$t1,	$a0,	$t0
bne	$t0,	$a0,	loop2
jr	$ra

gauss:
add	$v0,	$0,	$0
addi	$t2,	$0,	2
addi	$t0,	$a0,	-1
mult	$t0,	$a0
mflo	$t1
div	$v0,	$t1,	$t2
jr	$ra