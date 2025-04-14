#include<stdio.h>

int main()
{
    int n, k, i;
    int a[10000];
    int sl;
    scanf("%d %d", &n, &k);
    sl=1;
    for (i=1; i<=n; i++)
    {
        if (n % i ==0)
        {
            a[sl]=i;
            sl=sl+ 1;
        }
    }
    sl=sl-1;

    /*
    for (int j=1; j<=sl; j++)
    {
        printf("%d ", a[j]);
    }
    printf("\n");
    */

    if (k>sl)
    {
        printf("%d", -1);
    }
    else
    {
        printf("%d", a[k]);
    }
    return 0;
}
