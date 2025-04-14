#include<stdio.h>
#include<stdbool.h>


int ucln(int a, int b)
{
    int r;
    while (a%b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return b;
}


bool kt(int b)
{
    int i=2;
    while (b>1)
    {
        while (b%i==0)
        {
            if (i!=2 && i!=5) return false;   //neu b co thua so khac 2 hoac 5 thi la so vo han tuan hoan
            b=b/i;
        }
        i=i+1;
    }
    return true;
}


void xuli(int a, int b)
{
    while (a>0)
    {
        a=a*10;
        printf("%d", a/b);
        a=a%b;
    }
    return;
}


int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int t=ucln(a, b);
    a=a/t;
    b=b/t;
    printf("%d ", a/b);
    if (kt(b)==false) printf("-1"); else xuli(a%b, b);
    return 0;
}
