#include<stdio.h>
#include<stdbool.h>


bool kt(long long n)
{
    long long t=n%10;
    while (n>0)
    {
        if (n%10!=t) return false;
        n=n/10;
    }
    return true;
}

int main()
{
    long long n;
    scanf("%lld", &n);
    /*for (long long i=0; i<n; i++)
    {
        long long dem=0, m;
        scanf("%lld", &m);
        for (long long j=1; j<=m; j++) if (kt(j)==true) dem=dem+1;
        printf("\n%d", dem);
    }*/
    long long
    if (kt())
    return 0;
}
