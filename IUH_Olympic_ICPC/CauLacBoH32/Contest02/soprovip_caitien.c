#include<stdio.h>


void xuli(long long m)
{
    if (1<=m && m<=9)
    {
        printf("%lld\n", m);
        return;
    }
    else if (10<=m && m<=99)
    {
        printf("%lld\n", 9+m/11);
        return;
    }
    else if (100<=m && m<=999)
    {
        printf("%lld\n", 18+m/111);
        return;
    }
    else if (1000<=m && m<=9999)
    {
        printf("%lld\n", 27+m/1111);
        return;
    }
    else if (10000<=m && m<=99999)
    {
        printf("%lld\n", 36+m/11111);
        return;
    }
    else if (100000<=m && m<=999999)
    {
        printf("%lld\n", 45+m/111111);
        return;
    }
    else if (1000000<=m && m<=9999999)
    {
        printf("%lld\n", 54+m/1111111);
        return;
    }
    else if (10000000<=m && m<=99999999)
    {
        printf("%lld\n", 63+m/11111111);
        return;
    }
    else if (100000000<=m && m<=999999999)
    {
        printf("%lld\n", 72+m/111111111);
        return;
    }
}


int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        long long m;
        scanf("%lld", &m);
        xuli(m);
    }
    return 0;
}
