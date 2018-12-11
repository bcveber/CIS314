/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

unsigned int extract (unsigned int x, int i)
{
  signed int y = x;
  int multiplier = i << 3;
  
  int multi1 = 24 - multiplier;
 
  y = y << multi1;
  y = y >> 24;
  
  //multiply the given int i val to find the position of the value in
  //question. then, set up another multiplier that will account for the move
  //within the 32 bit that is the remainder of the position from the i.
  //once you have performed the shift to make the given value go to the
  //front, you shift it again by 24 to make it go to the back onfe again.
  //it is 24 because you have to leave 8 out to account for the actual
  //value being shifted
  //ex: 0xABCDEF00 --> (first shift left) 0xCD000000 ---> 2nd shift right)
  //0xFFFFFFCD

  return y;
}

int main ()
{
  int test1 = 0x12345678;
  int test2 = 0xABCDEF00;
  int val = 0;
  int val2 = 2;
  printf ("%08X", extract (test1, val));

  return 0;
}

