#include<stdio.h>

int main()
{
    int n, i, s;
    printf ("Nhap n = "); scanf ("%d", &n);
    s=0;
    for (i=1; i<=n; i++)
    {
        s=s+i;
    }
    printf("Tong = %d", s);
    return 0;
}

