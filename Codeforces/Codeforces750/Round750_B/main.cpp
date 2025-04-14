#include<stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        long long d1=0, d2=1;
        long long tam;
        for (int i=0; i<n; i++)
        {
            scanf("%lld", &tam);
            if (tam==1) d1=d1+1;
            if (tam==0) d2=d2*2;
        }
        printf("%lld\n", d1*d2);
    }
    return 0;
}
