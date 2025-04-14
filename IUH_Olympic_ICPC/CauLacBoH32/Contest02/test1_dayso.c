#include<stdio.h>

int main()
{
    long a[100000];
    a[1]=1;
    long n, tong=1;
    scanf("%d", &n);
    int i=2, d=1;;
    while (1==1)
    {
        a[i]=1-((a[i-1]-1)-1);
        //printf("\n%d %d", i, a[i]);
        if (a[i]%2==1)
        {
            tong=tong+a[i];
            d=d+1;
            if (d>=n) break;
        }
        i=i+1;
    }

    //for (int i=1; i<=n; i++) printf("%d ", a[i]);
    printf("%d", tong);
    return 0;
}
