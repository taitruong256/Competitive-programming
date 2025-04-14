#include<stdio.h>
#include<stdbool.h>


bool kt(long long n)
{
    long long t=n%10;
    while (n>0)
    {
        if (n%10!=t) return false;
        n=n/10;
    }
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        int dem=0, m;
        scanf("%d", &m);
        for (int j=1; j<=m; j++) if (kt(j)==true)
        {
            dem=dem+1;
            printf("\n-----------%d", j);
        }
        printf("\n%d", dem);
    }

    return 0;
}
