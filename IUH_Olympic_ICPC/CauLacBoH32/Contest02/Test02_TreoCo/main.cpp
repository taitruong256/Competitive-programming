#include<stdio.h>

int main()
{
    int max=0, n, k, d[256]={0}, d1[256]={0}, d2[256]={0}, a[10000], b[10000];
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        d1[a[i]]=d1[a[i]]+1;
        if (a[i]>max) max=a[i];
    }
    for (int i=0; i<k; i++)
    {
        scanf("%d", &b[i]);
        d2[b[i]]=d2[b[i]]+1;
        if (b[i]>max) max=b[i];
    }
    for (int i=0; i<=max; i++) d[i]=d1[i]+d2[i];


    for (int i=0; i<max-1; i++) if (d[i]>0)
    {
        for (int j=0; j<max; j++) if (d[j]>0 && d[i]<d[j])
        {
            int t=d[i];
            d[i]=d[j];
            d[j]=t;
        }
    }



    int s=0, dem=0;
    for (int i=0; s<n; i++) if (d[i]>0)
    {
        if (s+d[i]>=n)
        {
            s=s+d[i];
            d[i]=n-s;
        }
        else s=s+d[i];
        dem=dem+(d[i]-d1[i]);
    }

    printf("%d", dem);
    return 0;
}
