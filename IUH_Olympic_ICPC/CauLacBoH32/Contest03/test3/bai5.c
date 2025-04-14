#include<stdio.h>
#include<string.h>


char * donvi(int s)
{
    if (s==1) return "one";
    else if (s==2) return "two";
    else if (s==3) return "three";
    else if (s==4) return "four";
    else if (s==5) return "five";
    else if (s==6) return "sex";
    else if (s==7) return "seven";
    else if (s==8) return "eight";
    else if (s==9) return "nine";
    return "zero";
}

void xuli(int s)
{
    printf("%s", donvi(s));
    return;
}


int main()
{
    int s;
    scanf("%d", &s);
    xuli(s);
    return 0;
}
