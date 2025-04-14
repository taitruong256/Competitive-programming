#include<stdio.h>

int pp()
{
    int n, m;
    int a[10000], b[10000], d[256];
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        d[a[i]]=d[a[i]]+1;
    }
    for (int i=0; i<m; i++)
    {
        scanf("%d", &b[i]);
        d[b[i]]=d[b[i]]+1;
    }

    for (int i=0; i<255; i++) if (d[i]>0)
    for (int j=i+1; j<256; j++) if (d[j]>0 && d[i]>d[j])
    {
        int t=d[i];
        d[i]=d[j];
        d[j]=t;
    }

    int s=0, dem=0;
    for (int i=0; s<n; i++) if (d[i]>0)
    {
        s=s+d[i];
        dem=dem+1;
    }

    printf("%d", dem);
    return 0;
}
