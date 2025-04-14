#include<stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
    int n;
    scanf("%d", &n);
    long long a[101];
    for (int i=1; i<=n; i++) scanf ("%lld", &a[i]);
    long long max=0;
    for (int i=1; i<=n; i++) if (a[i]-i>max) max=a[i]-i;
    printf("%lld\n", max);
    }
    return 0;
}
