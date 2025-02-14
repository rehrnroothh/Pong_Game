  # labwork.S
  # Written 2015-2017 by F Lundevall
  # Skeleton file for IS1200/IS1500 lab 1.
  # The macros PUSH and POP are in the public domain.
  # Please add your own code at the end of the file.

  #
  # Please keep the two macros PUSH and POP unchanged
  #

.macro	PUSH reg
	addi	$sp,$sp,-4
	sw	\reg,0($sp)
.endm

.macro	POP reg
	lw	\reg,0($sp)
	addi	$sp,$sp,4
.endm
  #
  # Please add your own code below this line
  #
# timetemplate.asm
  # Written 2015 by F Lundevall
  # Copyright abandonded - this file is in the public domain.
	.global time2string, delay, enable_interrupt
	.data
	.align 2
mytime:	.word 0x5957
timstr:	.ascii "text more text lots of text\0"
	.text
main:
	# print timstr
	la	$a0,timstr
	li	$v0,4
	syscall
	nop
	# wait a little
	li	$a0,500 #load 1000ms
	jal	delay
	nop
	# call tick
	la	$a0,mytime
	jal	tick
	nop
	# call your function time2string
	la	$a0,timstr
	la	$t0,mytime
	lw	$a1,0($t0)
	jal	time2string
	nop
	# print a newline
	li	$a0,10
	li	$v0,11
	syscall
	nop
	# go back and do it all again
	j	main
	nop
# tick: update time pointed to by $a0
tick:	lw	$t0,0($a0)	# get time
	addiu	$t0,$t0,1	# increase
	andi	$t1,$t0,0xf	# check lowest digit
	sltiu	$t2,$t1,0xa	# if digit < a, okay
	bnez	$t2,tiend
	nop
	addiu	$t0,$t0,0x6	# adjust lowest digit
	andi	$t1,$t0,0xf0	# check next digit
	sltiu	$t2,$t1,0x60	# if digit < 6, okay
	bnez	$t2,tiend
	nop
	addiu	$t0,$t0,0xa0	# adjust digit
	andi	$t1,$t0,0xf00	# check minute digit
	sltiu	$t2,$t1,0xa00	# if digit < a, okay
	bnez	$t2,tiend
	nop
	addiu	$t0,$t0,0x600	# adjust digit
	andi	$t1,$t0,0xf000	# check last digit
	sltiu	$t2,$t1,0x6000	# if digit < 6, okay
	bnez	$t2,tiend
	nop
	addiu	$t0,$t0,0xa000	# adjust last digit
tiend:	sw	$t0,0($a0)	# save updated result
	jr	$ra		# return
	nop

  # you can write your code for subroutine "hexasc" below this line
  #
  hexasc:
  andi $a0, $a0, 0xF # extract the 4 least significant bits
  li $t2, 9
  bgt $a0, $t2, tenToFifthen
  nop
  zeroToNine:
  addi $v0, $a0, 48
  jr $ra
  nop
  
  tenToFifthen:
  addi $v0, $a0, 55
  jr $ra
  nop
  
  time2string: #stores the the ACII coded didgets at the adress of timster
  PUSH	$ra #saves return adress so that we can use jal hexasc
  move $t0, $a0 #sets the value of t0 to the value of a0 = adress of timster
  andi $a0, $a1, 0xF000 #extracting the ten minutes
  srl $a0, $a0, 12 #shift right to align with hexasc
  jal hexasc
  nop
  sb $v0, 0($t0) #stores a byte at the adress of t0 offset 0
  
  andi $a0, $a1, 0xF00 #extracting the one minutes
  srl $a0, $a0, 8 #shift right to align with hexasc
  jal hexasc
  nop
  sb $v0, 1($t0)
  
  li $t1, 0x3A # load and store a :
  sb $t1, 2($t0)
  
  andi $a0, $a1, 0xF0 #extracting the ten seconds
  srl $a0, $a0, 4 #shift right to align with hexasc
  jal hexasc
  nop
  sb $v0, 3($t0)
  
  andi $a0, $a1, 0xF #extracting the one seconds
  
  li $t5, 2
  beq $a0, $t5, two
  nop
  jal hexasc
  nop
  sb $v0, 4($t0)
  
  
  li $t1, 0x00		#a null byte at the adrees of t0 offset 5
  sb $t1, 5($t0)
  
  POP $ra 	#next time jr $ra is used we will jump back to all the way
  jr $ra
  nop
  
  two:
  li $t6, 0x54
  sb $t6, 4($t0)
  
  li $t6, 0x57
  sb $t6, 5($t0)
  
  li $t6, 0x4f
  sb $t6, 6($t0)
  
   li $t1, 0x00		#a null byte at the adrees of t0 offset 5
  sb $t1, 7($t0)
  
  POP $ra 	#next time jr $ra is used we will jump back to all the way
  jr $ra
  nop
  

delay:
    PUSH    $ra
    addi    $t3, $a0, 0         # Copy arg to t3 wish is "ms"

while:
    blez    $t3, done           #goes to "done" if $t3 less then or equall to 0 "== 0 in our case" in c code ("ms > 0")
    nop
    addi    $t3, $t3, -1         # ms - 1

    li      $t4,4777            # loads a constant into t4
    li      $t5, 0               # i = 0

for:	#this loop does nothing each cyckle to slow down the clock based on speed of clock and delay between operations
    bge     $t5, $t4, while      # Exit if i >= *t4
    nop
    addi    $t5, $t5, 1          # i++
    j       for
    nop

done:
    POP     $ra
    jr      $ra
    nop

enable_interrupt:
    ei
    jr $ra
    nop