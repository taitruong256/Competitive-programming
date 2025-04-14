#include<stdio.h>

int main()
{

    long long a, b, n;
    scanf("%lld%lld%lld", &a, &b, &n);
    if (a>=n || b>=n) printf("0");
    else if (a<=0 && b<=0 && a<n && b<n) printf("-1");
    else
    {
        long long d=0;
        while (a<n && b<n)
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
