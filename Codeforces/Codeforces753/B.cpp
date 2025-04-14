#include<stdio.h>

int main()
{
    long long t;
    scanf("%lld", &t);
    while (t--)
    {
        long long x, n;
        scanf("%lld%lld", &x, &n);
        long long t=n%4;
        for (long long i=n-t+1; i<=n; i++)
        {
            if (x%2==0) x=x-i; else x=x+i;  //printf("%lld-->", x);
        }
        printf("%lld\n", x);
    }
    return 0;
}
