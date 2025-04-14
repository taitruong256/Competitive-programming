#include<stdio.h>
#include<math.h>

long long xuli(long long a, long long b, long long d)
{
    int m;
    m=abs(a-b);
    if (a>m*2 || b>m*2 || d>m*2) return -1;
    else
    {
        if (d+m>m*2) return d+m-m*2;
        else return d+m;
    }

    //printf("\n%lld  %lld  %lld", a, b, d);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        long long a, b, d;
        scanf("%lld %lld %lld", &a, &b, &d);
        printf("\n%lld", xuli(a, b, d));
    }
    return 0;
}
