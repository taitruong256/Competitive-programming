#include<stdio.h>

int main()
{
    int i, n, max, dmax;
    int a[10000]={}, d[10000]={};
    scanf("%d", &n);
    max=0;
    for (i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        d[a[i]]=d[a[i]]+1;
        if (a[i] > max)
        {
            max=a[i];
        }
    }

    dmax=0;
    for (i=0; i<=max; i++)
    {
        if (d[i]>d[dmax])
        {
            dmax=i;
        }
    }
    printf("%d", dmax);
    return 0;
}
