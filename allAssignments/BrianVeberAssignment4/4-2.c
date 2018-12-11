#include <stdio.h>

/*
movl (%edx), %esi //first pointer comparing i and 0(array size)
movl (%eax), %ecx //2nd pointer comparing 0(array size) and i
addl $4, %eax //prep for swap - t0
addl $40, %edx //t1
movl %esi, -4(%eax) //swap (2 lines) ---*xp
movl %ecx, -40(%edx) // --- *yp
cmpl %ebx, %eax //compares j and i
jne .L3 //j less than i
*/

#define N 10 //define N
typedef int array_t[N][N]; //declare array_t of size N
int *rp; //declare pointers
int *cp; //declare pointers

void transpose(array_t a) {
    for (int i=0; i<N; ++i){
        
        //pointers to cycle through each array location (value)
        rp = &a[i][0]; //movl edx and eax
        cp = &a[0][i];
        for (int j =0; j<i; ++j){ //jne comparision
            
            //swap (rp,cp) -- run swap function for the 2 pointers
            int t0 = *rp;
            int t1 = *cp;
            *rp = t1;
            *cp = t0;
            
            //accounts for addl $4/$40 and movl -4/-40:
            rp += 1; //will always be +1 for rp
            cp += N; //(n*1) will just become n. comes from dividing the 40 bits by 10(N)
        }
    
    }
}

int main(){
    
    
    array_t a = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    transpose(a);
    
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            printf("%d ", a[i][j]);
    }
    printf("\n");
    } 
    
    return 0;
}


