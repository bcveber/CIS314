#include <stdio.h>

/*
int sum(int from, int to) {
 int result = 0;
 do {
 result += from;
 ++from;
 } while (from <= to);
 return result;
}
*/

int sum(int from, int to) {
int result = 0;
// Ensure that argument *from* is in %ecx,
// argument *to* is in %edx, *result* is in %eax - do not modify.
__asm__ ("movl %0, %%ecx # from in ecx;" :: "r" ( from ));
__asm__ ("movl %0, %%edx # to in edx;" :: "r" ( to ));
__asm__ ("movl %0, %%eax # result in eax;" :: "r" ( result ));
// Your IA32 code goes below - comment each instruction...
__asm__(
".LOOP:" //label the loop
"addl %ecx, %eax;" //add the result and from
"addl $1, %ecx;" //add 1 to from (++from)
"cmpl  %edx, %ecx;" //compare from and to
"jle .LOOP;" //jle = see if from is less than or equal to "to"
);
// Ensure that *result* is in %eax for return - do not modify.
__asm__ ("movl %%eax, %0 #result in eax;" : "=r" ( result ));
return result;
}




int main()
{
    //printf("jsdfjas");
    printf("%d ", sum(1,6));
    printf("%d ", sum(3,5));

    return 0;
}
