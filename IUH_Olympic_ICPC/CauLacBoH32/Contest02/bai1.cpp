#include<conio.h>
#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    int n, i, s;
    printf ("Nhap n = "); scanf ("%d", n);
    s=0;
    printf("%d", n);
    for (i=1; i<=n; i++)
    {
        s=s+i;
    }
    printf("Tong = %d", s);
    getch();
    return 0;
}
