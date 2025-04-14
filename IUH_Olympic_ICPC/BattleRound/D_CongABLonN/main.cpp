#include<stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        long long a, b, n;
        scanf("%lld%lld%lld", &a, &b, &n);
        long long d=0;
        while (a<=n && b<=n)
        {
            if (a<b)
            {
                d=d+1;
                a=a+b;
            }
            else
            {
                d=d+1;
                b=a+b;
            }
        }

    printf("%lld\n", d);
    }

    return 0;
}
