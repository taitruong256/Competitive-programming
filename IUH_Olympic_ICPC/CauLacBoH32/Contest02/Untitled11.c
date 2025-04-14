#include<stdio.h>
#include<conio.h>

int main()
{
    int n, m, i, j;
    int a[100][100];

    scanf("%d", &n);
    scanf("%d", &m);
    printf("%d %d", n, m);
   /* for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (j=0; j<m; j++)
    {
        int max=0;
        for (i=0; i<n; i++)
        {
            if (a[i][j]>max)
            {
                max=a[i][j];
            }
        }
        printf("%d ", max);
    }*/
    return 0;
}
