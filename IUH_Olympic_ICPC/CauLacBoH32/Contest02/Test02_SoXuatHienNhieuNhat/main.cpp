#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[10000], d[10000];


    for (int i=0; i<10000; i++) d[i]=0;
    for (int i=0; i<n; i++) scanf("%d", &a[i]);  //nhap
    for (int i=0; i<n; i++) d[a[i]]++;


    int dmax=1;
    for (int i=1; i<10000; i++)  if (d[i]>d[dmax]) dmax=i;   //tim gia tri xuat hien nhieu nhat
    printf("%d", dmax);
    return 0;
}
