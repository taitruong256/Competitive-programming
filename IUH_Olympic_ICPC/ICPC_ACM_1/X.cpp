#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d:\n", n);
    int t, dem=0;
    if (n%2==0) t=n/2; else t=n/2+1;
    for (int i=2; i<=t; i++)
    {
        int s=0;
        int d=0;
        while (s<n)
        {
            ++d;
            if (d%2==1) s=s+i; else s=s+i-1;
        }
        if (s==n)
        {
            ++dem;
            printf("%d,%d\n", i, i-1);
        }

        s=0;
        while (s<n) s=s+i;
        if (s==n) printf("%d,%d\n", i, i);
    }
    return 0;
}
