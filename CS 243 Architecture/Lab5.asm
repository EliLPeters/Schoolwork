	.data
orig:	.asciiz	"The original number was: "
newn:	.asciiz "\nThe shifted number is: "
thing:	.word	48768

	.text
main:
lw	$s0 thing

srl	$s1 $s0	7

la	$a0 orig
li	$v0	4
syscall
move	$a0	$s0
li	$v0	1
syscall

la	$a0	newn
li	$v0	4
syscall
move	$a0	$s1
li	$v0	1
syscall

li	$v0	10
syscall