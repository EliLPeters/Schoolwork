# Lab 3
# Eli Peters
	.data
endl:	.asciiz "\n"
welcm:	.asciiz	"I will square an integer value for you!"
enter:	.asciiz "Please enter your value: "
answer:	.asciiz "The square of your value is: "
toolrg:	.asciiz "Result was too high!"

	.text
main:
la	$a0, welcm
li	$v0, 4
syscall
la	$a0, endl
li	$v0, 4
syscall

la	$a0, enter
li	$v0, 4
syscall
la	$a0, endl
li	$v0, 4
syscall

li	$v0, 5
syscall
move	$s0, $v0
move	$t0, $s0

mult	$s0, $t0
mflo	$s1
mfhi	$t1

bne	$t1, 0, big

la	$a0, answer
li	$v0, 4
syscall
move	$a0, $s1
li	$v0, 1
syscall
li	$v0, 10
syscall

big:
la	$a0, toolrg
li	$v0, 4
syscall
li	$v0, 10
syscall