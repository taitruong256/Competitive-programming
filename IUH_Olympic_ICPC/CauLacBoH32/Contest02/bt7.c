#include<stdio.h>

int main()
{
    int l, r, d, i, sl, tong, j;
    int a[10];
    scanf("%d %d", &l, &r);

    tong=0;
    for (j=l; j<=r; j++)
    {
        int n=j;
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
            if (a[i]==1)
            {
                d=d+1;
            }
        }
        tong=tong+d;
    }

    printf("%d", tong);
    return 0;
}

