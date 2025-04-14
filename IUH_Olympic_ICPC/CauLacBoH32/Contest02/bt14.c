#include<stdio.h>

int main()
{
    int i, n, s;
    int a[10000];
    scanf("%d", &n);
    s=0;
    for (i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] % 2 ==1)
        {
            s=s+a[i];
        }
    }
    printf("%d", s);
    return 0;
}
