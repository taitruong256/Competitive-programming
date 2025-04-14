#include<stdio.h>
#include<stdbool.h>


bool kt(long long n)
{
    if (1<=n && n<=9) return true;
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
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        long long dem=0, m;
        scanf("%lld", &m);
        for (long long j=1; j<=m; j++) if (kt(j)==true) dem=dem+1;
        printf("\n%d", dem);
    }


    //long long tam;
    //tam=2;
    //if (kt(tam)==true) printf("\n%lld la so pro vip", tam); else printf("\n%lld khong phai la so pro vip", tam);

    return 0;
}
