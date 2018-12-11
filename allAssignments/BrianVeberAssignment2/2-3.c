#include <stdio.h>

int ge(float x, float y) {
 unsigned int ux = *((unsigned int*) &x); // convert x raw bits
 unsigned int uy = *((unsigned int*) &y); // convert y raw bits
 unsigned int sx = ux >> 31; // extract sign bit of ux
 unsigned int sy = uy >> 31; // extract sign bit of uy
 ux <<= 1; // drop sign bit of ux
 uy <<= 1; // drop sign bit of uy
 // TODO: return using sx, sy, ux, uy
 return ux <= uy == 1 || sx >= sy == 0 || ux >= uy == 0 ||sx <= sy == 1; 
 
 //I have 4 cases shown above. For when they are both 0, then we
 //have to take in account the 1 and -1 scenarios, which are for the
 //next 2. Finally, we account for values when it is larger and/or
 //smaller which is the 4th one. The 1st one takes out the signs (works)
 //and then the next 2 look at signed and unsigned 1s (for the 1 and -1)
 //then you compare the sx and sy in the last one to see general bigger
 //or smaller.
 
}

int main(){

    
    
    printf("%i", ge(0.0f, 0.0f));
    printf("\n");
    
    printf("%i", ge(-0.0f, 0.0f));
    printf("\n");
    
    printf("%i", ge(-1.0f, 0.0f));
    printf("\n");
    
    printf("%i", ge(0.0f, 1.0f));
    printf("\n");
    
    printf("%i", ge(1.0f, 0.0f));
    printf("\n");
    
    printf("%i", ge(0.0f, -1.0f));
    printf("\n");
    
    return 5;
}


