#include<stdio.h>


long long ucln(long long a,long long b)
{
    long long r=a%b;
    while (a%b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return b;
}

long long tongcs(long long n)
{
    long long s=0;
    while (n>0)
    {
        s=s+n%10;
        n=n/10;
    }
    return s;
}


int main()
{
    long long n;
    scanf("%lld", &n);
    long long i=n;
    while (0==0)
    {
        if (ucln(i, tongcs(i))>1) break;
        i=i+1;
    }
    printf("%lld", i);
    return 0;
}
