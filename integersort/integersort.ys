#sorts an array of integers with sort and swap.

.pos 0
Init:
    irmovl Stack, %esp
    irmovl Stack, %ebp
    call Main
    halt
    
    # Array of 4 elements
	.align 4	
array:	
    .long 0x0002
	.long 0x0001
	.long 0x0004
	.long 0x0006
	.long 0x0003
	.long 0x0010
	.long 0x0005
	.long 0x0007
	.long 0x0008
	.long 0x0009
	
Main:

    pushl	%ebp
	rrmovl	%esp, %ebp
	
	//#pushl $10
	irmovl $10, %eax //#define N 10
	
	//#pushl $array
	pushl %eax
    irmovl array, %edx //#global int array
    pushl %edx
    call bubbleSort
    
    //#addl $8, %esp
    rrmovl %ebp, %esp
    popl %ebp
    
    //#leave
    ret
    
bubbleSort:
    pushl %ebp
    rrmovl %esp, %ebp
    //#pushl %edi
    //#pushl %esi
    pushl %ebx
    mrmovl	8(%ebp), %edi //#beg address of array
	
	//#leal	-1(%eax), %esi //count-1
	mrmovl	12(%ebp), %esi //#count
	
	andl %esi, %esi //#is count-1 zero?
	je .L1

.L5: //#Inner for-loop of sort
    mrmovl 8(%ebp), %edi //#array
    mrmovl (%edi), %ecx //#j (data+j)
    mrmovl 4(%edi), %edx //#j+1 (data+j+1)
    
    //#cmpl	%edx, %ecx //is edx < ecx?
    irmovl $-1, %ebx
    xorl %eax, %eax /#make j set to 0
    addl %ebx, %esi //#subtract from size
    
    
.L4: //#prepare for next inner loop iter
    irmovl $1, %ebx
    addl %ebx, %eax //#j++
    //#cmpl %ebx, %eax //is count-i-1 < j?
    rrmovl %ecx, %ebx //#check j and count (from above)
    subl %edx, %ebx
    jle .L6
    
Swap: #//swap executes if jle fails above

    rrmovl %ecx, %ebx
    rmmovl %edx, (%edi) //#J+1 to array pos j (array = %edi)
    rmmovl %ebx, 4(%edi) //#J to array pos j+1
    
.L6: //#tees up the next set of indexes in array
    rrmovl %esi, %ebx
    subl %eax, %ebx //#comp j and count
    je .L5 
    
    irmovl $4, %ebx
    addl %ebx, %edi //# go to next array val
    mrmovl (%edi), %ecx //# get the next j index
    mrmovl 4(%edi), %edx //# get the next j+1 index
    jmp .L4
    
.L1:
    popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret  //#Return to main
    
 .pos 0x100
Stack:
