#include<stdio.h>
#include<stdbool.h>


bool kt(long long n)
{
    while (n>0)
    {
        if (n%10==0) return false;   //99 100
        n=n/10;
    }
    return true;
}

int main()
{
    long long n;
    scanf("%lld", &n);
    long long i=n+1;
    while (kt(i)==false) ++i;
    printf("%lld", i);
    return 0;
}
