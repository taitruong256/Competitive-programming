#include<stdio.h>

int main()
{
    int n, d, i, j, dem;
    scanf("%d %d", &n, &d);
    int a[10000];
    for (i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    dem=0;
    for (i=0; i<n; i++)
    {
        for (j=i+1; j<n; j++)
        {
            if (a[i]+a[j]==d)
            {
                dem=dem+1;
            }
        }
    }
    printf("%d", dem);
}
