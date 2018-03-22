.data
counter	.word	0

.text
pixelSum:
# stack frame
addi,	$sp,	-12
sw,		$a0,	0($sp)
sw,		$a1,	4($sp)
sw,		$ra,	8($sp)
# test conditional
blt,	$a0,	$t5,	ELSE
blt,	$a1,	$t6,	ELSE
# base case
lw,		$v0,	counter
j,	PS_END
ELSE:
# (temporarily) mutate a0 and a1
addi,	$a0,	$a0,	1
addi,	$a1,	$a1,	2
# recur
jal,	pixelSum
add,	$t3,	$v0,	$zero
# restore a0 and a1
lw,		$a0,	0($sp)
lw,		$a1,	4($sp)
# mutate a0 and a1 again
addi,	$a0,	$a0,	2
addi,	$a1,	$a1,	1
# recur again
jal,	pixelSum
# add results and 1
add,	$v0,	$v0,	$t3
addi,	$v0,	$v0,	1
PS_END:
# pop stack
lw,		$a0,	0($sp)
lw,		$a1,	4($sp)
lw,		$ra,	8($sp)
addi,	$sp,	12
jr,		$ra