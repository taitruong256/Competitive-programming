#include<stdio.h>


int main()
{
    long long t;
    scanf("%lld", &t);


    int d[100001]={0};
    int a[2001][2001];
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i=0; i<n; i++) scanf("%d", &a[0][i]);


        for (int i=1; i<=n; i++)
        {
            for (int j=0; j<=n; j++) d[j]=0;//khoi tao
            for (int j=0; j<n; j++) ++d[a[i-1][j]];
            for (int j=0; j<n; j++) a[i][j]=d[a[i-1][j]];
        }

        long long q;
        scanf("%lld", &q);
        for (long long i=0; i<q; i++)
        {
            long long x, k;
            scanf("%lld%lld", &x, &k);
            printf("%d\n", k<=n?a[k][x-1]:a[n][x-1]);
        }
    }
    return 0;
}
