#include<stdio.h>

long long sochia(long long n)
{
    long long tam=0;
    for (long long i=0; i<n; i++) tam=tam*10+1;
    return tam;
}

void xuli(long long m)
{
    long long t=m;
    long long d=0;
    while (t>0)
    {
        d=d+1;
        t=t/10;
    }
    printf("%d\n", 9*(d-1)+m/sochia(d));

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

