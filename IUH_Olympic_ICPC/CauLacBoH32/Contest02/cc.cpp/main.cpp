#include<stdio.h>
#include<algorithm>

using namespace std;




int main()
{
    long long t;
    scanf("%lld", &t);
    while (t--)
    {
        long long n;
        scanf("%lld", &n);
        long long a[n+1];
        for (long long i=0; i<n; i++) scanf("%lld", &a[i]);

        for (long long i=0; i<n-1; i++)
        for (long long j=i+1; j<n; j++) if (a[i]>a[j])
        {
            long long tam=a[i];
            a[i]=a[j];
            a[j]=tam;
        }

        long long gtmin=-10000000000000;
        for (long long i=0; i<n; i++)
        {
            for (long long j=i+1; j<n; j++) a[i]=a[i]-a[j];
            if (a[i+1]>gtmin) gtmin=a[i+1];
        }

        printf("%lld\n", gtmin);
    }
    return 0;
}
