init:	irmovl Stack, %esp  	# Set up stack pointer  
	irmovl Stack, %ebp  	# Set up base pointer   
	call Main		# Execute main program
	halt			# Terminate program 

# Array of 4 elements
	.align 4 	
xp:	.long 0x0001
yp:	.long 0x0002

# tested function. When tested, it successfully switches (addr --- value)  
# 0014 --- 01000000 and 0018 ---- 02000000 to the following:
# 0014 --- 02000000 and 0018 ---- 01000000.

Main:	pushl %ebp 
	rrmovl %esp,%ebp
	irmovl yp,%eax	
	pushl %eax # push yp
	irmovl xp,%eax
	pushl %eax # push xp
	call Swap
	rrmovl %ebp,%esp
	popl %ebp
	ret 

# int Swap(int *xp, int *yp)
Swap:	pushl %ebp
	rrmovl %esp,%ebp
	pushl %ebx
	# TODO - push callee-save registers?
	mrmovl 8(%ebp),%edx # edx = xp
    mrmovl 12(%ebp),%ecx # ecx = yp
    mrmovl (%ecx),%eax # eax = *yp
    mrmovl (%edx),%ebx # ebx = *xp
    rmmovl %eax,(%edx) # *xp = eax
    rmmovl %ebx,(%ecx) # *yp = ebx
	# TODO - swap
	popl %ebp
	ret

# The stack starts here and grows to lower addresses
	.pos 0x100
Stack:
