#include<stdio.h>

int main()
{
    int n, i, j, gt;
    //int a[10000][10000];

    scanf("%d", &n);
    gt=0;
    int bd=0;
    for (i=0; i<n; i++)
    {
        gt=bd;
        for (j=0; j<n; j++)
        {
                printf("%d ", gt);
                if (gt==0) gt=1; else gt=0;
        }
        printf("\n");
        if (bd==0) bd=1; else bd=0;
    }
    return 0;
}
