
#include <stdio.h>
/*
loop:
pushl %ebp //create register
movl %esp, %ebp //first 4 lines of code are for setting up the function only
pushl %esi //push %esi onto stack
pushl %ebx //push %ebx onto stack
//------
movl 8(%ebp), %esi //move int x onto %esi
movl 12(%ebp), %ecx //move int y onto %ecx
movl $2, %edx //set mask value to 2
movl $-1, %eax //set result value to -1

.L2: //loop
movl %esi, %ebx //move x onto %ebx
andl %edx, %ebx //mask&x
xorl %ebx, %eax // result^(mask&x)
sall %cl, %edx //mask<<y
cmpl $1, %edx //compare mask and 1 (mask > 1)
jg .L2 //jump to start of loop if the above comparison is greater than
popl %ebx //pop off %ebx (mask&x)
popl %esi //pop off %esi (x)
popl %ebp //pop off ebp (register)
ret //return result
*/

int loop(int x, int y) {
 int result = -1 ;
 for (int mask = 2; mask > 1; mask = mask<<y ) {
 result ^= (mask&x) ;
 }
 return result;
}

int main()
{
    int val1 = 1;
    int val2 = 5;
    printf("%d\n", loop(5,1));

    return 0;
}
