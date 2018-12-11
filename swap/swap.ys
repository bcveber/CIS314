#implements a swap procedure


init:	irmovl Stack, %esp  
	irmovl Stack, %ebp  	 
	call Main		
	halt		

	.align 4 	
xp:	.long 0x0001
yp:	.long 0x0002


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

Swap:	pushl %ebp
	rrmovl %esp,%ebp
	pushl %ebx
	mrmovl 8(%ebp),%edx # edx = xp
    mrmovl 12(%ebp),%ecx # ecx = yp
    mrmovl (%ecx),%eax # eax = *yp
    mrmovl (%edx),%ebx # ebx = *xp
    rmmovl %eax,(%edx) # *xp = eax
    rmmovl %ebx,(%ecx) # *yp = ebx
	popl %ebp
	ret

	.pos 0x100
Stack:
