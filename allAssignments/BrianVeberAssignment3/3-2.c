 #include <stdio.h>
 
int decode(int x, int y, int z){

    int b; //storage vals
    int a; //storage vals
    int c; //storage vals 
    a = y-z; //subtract y (%edx or 12(%ebp)) from z (16(%ebp)) = (subl 16(%ebp), %edx)
    b = x * a; //multiply x (8(%ebp) by a (y-z) = (imull 8(%ebp), %edx)
    a = a << 31; //left shift a = (sall $31, %eax)
    a = a >> 31; //right shift a = (sarl $31, %eax)
    c = b ^ a; //perform XOR on b and a (or %edx and %eax) = (xorl %edx, %eax)
    return c; //return final value
}

int main(void){
    
    unsigned int answer = decode(1,2,4);
    printf("%d\n", answer);

    unsigned int answerone = decode(-4,-8,-12);
    printf("%d\n", answerone);

    return 10000;
}