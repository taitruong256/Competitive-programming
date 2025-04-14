#include<stdio.h>

int main()
{
    int n, x, d, i, sl;

    scanf("%d %d", &n, &x);
    int a[10];
    sl=0;
    while (n>0)
    {
        a[sl]=n %10;
        n=n /10;
        sl++;
    }

    d=0;
    for (i=0; i<sl; i++)
    {
        if (a[i]==x)
        {
            d=d+1;
        }
    }
    printf("%d", d);
    return 0;
}
