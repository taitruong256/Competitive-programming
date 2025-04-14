#include<stdio.h>
const long sc=1000000000+7;

int main()
{
    long n, i;
    scanf("%d", &n);

    int a1=1, a2=1, an;
    if (n<=2) printf("%d", 1);
    else
    {
        for (i=3; i<=n; i++)
        {
            an=(a1+a2)%sc;
            a1=a2%sc;
            a2=an%sc;
        }
        printf("%d", an);
    }

    return 0;
}
