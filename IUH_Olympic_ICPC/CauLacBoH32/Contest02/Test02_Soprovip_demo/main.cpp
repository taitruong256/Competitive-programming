#include<stdio.h>

void xuli()
{
    int a[100];
    int n;
    scanf("%d", &n);
    int d=0;
    while (n>0)
    {
        a[d]=n%10;
        d=d+1;
        n=n/10;
    }


    int dem=0;
    for (int j=0; j<d; j++) if (a[j]>0) dem=dem+1;
    printf("%d\n", dem);


    for (int j=0; j<d; j++) if (a[j]>0)
    {
        printf("%d", a[j]);
        for (int k=0; k<j; k++) printf("0");
        printf(" ");
    }
    printf("\n");
}


int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        xuli();

    }
    return 0;
}
