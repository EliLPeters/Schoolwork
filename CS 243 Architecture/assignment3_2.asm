.text
isPrime:
# stack frame
addi,	$sp,	$sp,	-4
sw,		$ra,	0($sp)
# first if
mult,	$a1,	$a1
mflo,	$t0
blt,	$t0,	$a0,	SKIP1
addi,	$v0,	$zero,	1
j,		EXIT
SKIP1:
div,	$a0,	$a1
mfhi,	$t0
bne,	$t0,	$zero,	SKIP2
add,	$v0,	$zero,	$zero
j,		EXIT
SKIP2:
addi,	$a1,	$a1,	1
jal,	isPrime
EXIT:
lw,		$ra,	0($sp)
addi,	$sp,	4
jr,		$ra