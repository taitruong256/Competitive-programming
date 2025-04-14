#include<stdio.h>
#include<math.h>

int mu(int n)
{
    int t=1;
    for (int i=1; i<=n-1; i++) t=t*10;
    return t;
}

void xuli(int t)
{
    int a[10000];
    int m=0, d=0;

    while(t>0)
    {
        m=m+1;
        a[m]=t%10;
        if (a[m]!=0) d=d+1;
        t=t/10;
    }

    printf("%d\n", d);
    for (int i=m; i>=1; i--) if (a[i]!=0) printf("%d ", a[i]*mu(i));
    printf("\n");
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        int t;
        scanf("%d", &t);
        xuli(t);
    }
    return 0;
}
