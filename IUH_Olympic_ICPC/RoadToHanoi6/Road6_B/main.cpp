#include<stdio.h>

int main()
{
    long long n;
    scanf("%lld", &n);
    long long s=(n*(n+1))/2;// printf("%lld\n", s);
    long long i=0;
    long long s1=0, t=1;
    while (t<=n)
    {
        s1=s1+t;
        t=t*2;
    }                   //printf("%lld\n", s1);
    printf("%lld", (s-s1)-s1);
    return 0;
}
