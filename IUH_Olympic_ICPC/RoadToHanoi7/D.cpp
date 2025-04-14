#include<stdio.h>
#include<stdbool.h>

int main()
{
    long long n, a[10005];
    scanf("%lld", &n);
    for (long long i=1; i<=n; i++) scanf("%lld", &a[i]);


    if (n==1)
    {
        printf("Yes");
        return 0;
    }
    else
    {
        long long d1=0, d2=0;
        a[0]=-1;
        long long i, j;
        for (i=1; i<=n; i++) if (a[i]==a[i-1])
        {
            printf("No");
            return 0;
        }
        for (i=1; i<=n; i++) if (a[i]>a[i-1]) d1=d1+1; else break;
        for (j=i; j<=n; j++) if (a[j]<a[j-1]) d2=d2+1; else break;
        //printf("%lld, %lld\n", d1, d2);
        if (d1+d2==n) printf("Yes"); else printf("No");
    }
    return 0;
}
