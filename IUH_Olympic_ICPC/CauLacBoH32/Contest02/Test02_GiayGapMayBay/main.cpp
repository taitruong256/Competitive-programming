#include<stdio.h>

int main()
{
    int k, n, s, p;
    scanf("%d%d%d%d", &k, &n, &s, &p);
    int soto;
    if (n%s==0) soto=n/s; else soto=n/s+1;   // so to giay can cua 1 nguoi
    soto=soto*k;                     //so to giay cua k nguoi
    int sogoi;
    if (soto%p==0) sogoi=soto/p; else sogoi=soto/p+1;
    printf("%d", sogoi);
    return 0;
}
