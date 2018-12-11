#include <stdio.h>
#include <time.h>

int N = 4;
typedef int array_t[4][4];

int dim() {
    return N;
}


void f2(array_t a, int x, int y) {
    int dimval = dim(); //variable so you don't have to call dim() every time in the loop
    int xyval = x*y; //variable to limit multiplication of constants
    for (int i = 0; i < dimval; ++i) {
        for (int j = 0; j < dimval; ++j) {
            a[i][j] = i * xyval + j; //enter in this variable 'xyval' b/c x and y are constant values that can easily be replaced as such
        }
    }
}

void f1(array_t a, int x, int y) {
    for (int i = 0; i < dim(); ++i) {
        for (int j = 0; j < dim(); ++j) {
            a[i][j] = i * x * y + j;
        }
    }
}

int main()
{
    /*
    int n = 1000;
    int i = 0;
    array_t f;
    for(i=0; i<n; i++){
        f[i] = (int)(rand() % 10000) / n;
    }
    */
    array_t a = {{2.0, 2.0, 2.0, 2.0}, {1.5, 2.0, 1.4, 1.3}};
    array_t a1 = {{2.0, 2.0, 2.0, 2.0}, {1.5, 2.0, 1.4, 1.3}};
    int xval = 2;
    int yval = 3;
    
    clock_t t;
    clock_t b;
    
    t = clock();
    f2(a, xval, yval);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
 
    printf("f2() took %f seconds to execute \n", time_taken);
    
    b = clock();
    f1(a1, xval, yval);
    b = clock() - t;
    double time_taken2 = ((double)b)/CLOCKS_PER_SEC; // in seconds
 
    printf("f1() took %f seconds to execute \n", time_taken2);
    return 0;
}



