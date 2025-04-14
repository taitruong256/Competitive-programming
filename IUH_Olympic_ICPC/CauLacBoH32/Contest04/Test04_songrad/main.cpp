#include<stdio.h>

int main()
{
    int s, n;
    scanf("%d%d", &s, &n);
    int x[1000], y[1000];
    for (int i=0; i<n; i++) scanf("%d%d", &x[i], &y[i]);
    for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n; j++) if (x[i]>x[j])
    {
        int t=x[i];
        x[i]=x[j];
        x[j]=t;
        t=y[i];
        y[i]=y[j];
        y[j]=t;
    }

    int d=0;
    for (int i=0; i<n; i++) if (s>x[i])
    {
        s=s+y[i];
        d=d+1;
    }

    if (d==n) printf("YES"); else printf("NO");
    return 0;
}
