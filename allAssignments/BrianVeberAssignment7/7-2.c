#include <stdio.h>
#include <time.h>

//def N 24
typedef float array_f[20000];

void inner(float *u, float *v, int length, float *dest) {
    int i;
    float sum = 0.0f;
    for (i = 0; i < length; ++i) {
        sum += u[i] * v[i];
    }
 *dest = sum;
} 

void inner2(float *u, float *v, int length, float *dest) {
    int i;
    float sum = 0.0f;
    int iendval = length-3; //save time in loop by creating this variable
    for (i = 0; i < iendval; i+=4) { 
        sum += u[i] * v[i];
        sum += u[i+1] * v[i+1]; //unroll the loop here w/ 4 parallel accumulators below
        sum += u[i+2] * v[i+2]; 
        sum += u[i+3] * v[i+3]; 
    }
    for(; i<length; i++){ //clean up loop portion to take care of any "stragglers" or remainders
        sum += u[i] * v[i];
    }
    *dest = sum;
}

int main()
{
    int n = 20000;
    int i = 0;
    int y = 0;
    array_f u;
    array_f v;
    for(i=0; i<n; i++){
        u[i] = (double)(rand() % 10000) / n;
    }
    
    for(y=0; y<n; y++){
        v[i] = (double)(rand() % 10000) / n;
    }

    
    //array_f u = {3.5, 4.0, 4.5, 5.0, 5.5, 6.0, 2.0, 1.5, 1.6, 1.6, 5.5, 4.5, 3.5, 4.0, 4.5, 5.0, 5.5, 6.0, 2.0, 1.5, 1.6, 1.6, 5.5, 4.5};
    //array_f v = {2.0, 1.5, 1.6, 1.6, 5.5, 4.5, 3.5, 4.0, 4.5, 5.0, 5.5, 6.0, 3.5, 4.0, 4.5, 5.0, 5.5, 6.0, 2.0, 1.5, 1.6, 1.6, 5.5, 4.5};
    float result;
    
    clock_t t;
    clock_t b;
    
    t = clock();
    inner2(u, v, n, &result);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
 
    printf("inner2() took %f seconds to execute \n", time_taken);
    
    b = clock();
    inner(u, v, n, &result);
    b = clock() - t;
    double time_taken2 = ((double)b)/CLOCKS_PER_SEC; // in seconds
 
    printf("inner() took %f seconds to execute \n", time_taken2);
    return 0;
}


