#include<stdio.h>

int main()
{
    int i, n, s, max;
    int a[10000];
    scanf("%d", &n);
    max=0;
    for (i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > max)
        {
            max=a[i];
        }
    }
    printf("%d", max);
    return 0;
}
