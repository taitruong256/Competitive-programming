#include <stdio.h>

int main()
{
    long long t;
    scanf("%lld", &t);
    while (t--)
    {
        long long n;
        long long a[10001];
        scanf("%lld", &n);
        for (long long i=0; i<n; i++) scanf("%lld", &a[i]);
        if (n%2==0)
            for (long long i=0; i<n; i++) if (i%2==0) printf("%lld ", -a[i+1]); else printf("%lld ", a[i-1]);
        else
        {
            for (long long i=0; i<n-3; i++) if (i%2==0) printf("%lld ", -a[i+1]); else printf("%lld ", a[i-1]);
            if (a[n-3]+a[n-2]!=0) printf("%lld %lld %lld", a[n-1], a[n-1], -(a[n-3]+a[n-2]));
            else if (a[n-3]+a[n-1]!=0) printf("%lld %lld %lld", a[n-2], -(a[n-3]+a[n-1]), a[n-2]);
            else if (a[n-2]+a[n-1]!=0) printf("%lld %lld %lld", -(a[n-2]+a[n-1]), a[n-3], a[n-3]);
        }
        printf("\n");
    }
    return 0;
}
