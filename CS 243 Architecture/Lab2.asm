# Lab 2
# Eli Peters

	.data
welcm:	.asciiz	"I will create a ~*~*magic number*~*~ between 0 and 9, inclusive, and ask you to guess it!\n"
prompt:	.asciiz	"Enter your guess:\n"
toobig:	.asciiz	"Too big! Guess again...\n"
toosml:	.asciiz	"Too small! Guess again...\n"
gdjob:	.asciiz "You are right!\n"

	.text
main:
li	$s0, 4 #$s0 is the magic number

# Welcome the user
la	$a0, welcm
li	$v0, 4
syscall

#prompt for first guess
la	$a0, prompt
li	$v0, 4
syscall

#get value
li	$v0, 5
syscall
move	$s1, $v0

#compare
beq	$s1, $s0, finish

#clunky nonsense
loop:
blt	$s1, $s0, option2
la	$a0, toobig
li	$v0, 4
syscall

option2:
bgt	$s1, $s0, reprompt
la	$a0, toosml
li	$v0, 4
syscall

reprompt:
li	$v0, 5
syscall
move	$s1, $v0

bne	$s1, $s0, loop

finish:
#congratulations!
la	$a0, gdjob
li	$v0, 4
syscall
li	$v0, 10
syscall