#include <stdio.h>

int main()
{
    long long n, s=0;
    scanf("%lld", &n);

    long long t=1;
    for (int i=0; i<n; i++)
    {
        t=t*3;
        t=t%(1000000000+7);
        s=s+t;
        s=s%(1000000000+7);
    }
    printf("%lld", s%(1000000000+7));
    return 0;
}
