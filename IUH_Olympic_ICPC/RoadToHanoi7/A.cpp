#include<stdio.h>

int main()
{
    long long n, t;
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        long long d=1;
        while (n>0)
        {
            n=n/2;
            d=d+1;
        }
        printf("%lld\n", d);
    }
    return 0;
}
