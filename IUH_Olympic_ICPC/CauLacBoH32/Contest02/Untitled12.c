#include <stdio.h>
int main()
{
   float f = 1.123456789;
   char c[50]; //size of the number
    sprintf(c, "%f", f);
    printf(c);
    printf("\n");
}
