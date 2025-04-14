#include<stdio.h>

int main()
{
    int n, i;
    scanf("%d", &n);
    int a[26];

    a[0]=1;
    a[1]=1;
    for (i=2; i<n; i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
    printf("%d", a[n-1]);
    return 0;
}
