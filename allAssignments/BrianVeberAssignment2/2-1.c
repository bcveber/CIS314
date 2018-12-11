
#include <stdio.h>

int mask(int n){
    int shifter = ~0 << n; 
    int answer = ~0;

//shifter = all 1s with the shifted n values to make the appropriate n 0’s.  Answer = all 1s. Now you use the XOR operator on both, which will make all the 1=1 into 0s, and the n 0’s from the shifter will go with the 0=1 and make the n amount of 1s

//ex: n = 2. 111100 = shifter, 111111 = answer, answer ^ shifter = 000011
    
    return shifter ^ answer;
}

int main()
{
    int test1 = 1;
    printf("0x%x\n", mask(test1));

    return 0;
}
