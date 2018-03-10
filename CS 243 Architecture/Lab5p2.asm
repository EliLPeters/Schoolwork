	.data
enter:	.asciiz	"Enter the value: "
endl:	.asciiz "\n"
valu:	.asciiz "You entered: "
maskd:	.asciiz	"The masked value is: "
shiftd:	.asciiz "The shifted value is: "
tmask:	.word	15872

	.text
main:
# 2 863 311 530
# -1 431 655 766
# 15 872

la	$a0 enter
li	$v0	4
syscall

li $v0 5
syscall
move $s0 $v0

la	$a0	valu
li	$v0	4
syscall

move	$a0	$s0
li	$v0	1
syscall

la	$a0	endl
li	$v0	4
syscall

lw	$t0	tmask

and $s1 $s0 $t0

la	$a0	maskd
li	$v0	4
syscall

move	$a0	$s1
li	$v0	1
syscall

la	$a0	endl
li	$v0	4
syscall

sll $s2 $s1 10

la	$a0	shiftd
li	$v0	4
syscall

move	$a0	$s2
li	$v0	1
syscall

la	$a0	endl
li	$v0	4
syscall

li	$v0	10
syscall