#include<stdio.h>


void chuyen(int i)
{
    if (i==1) printf("Sheldon");
    else if (i==2) printf("Leonard");
    else if (i==3) printf("Penny");
    else if (i==4) printf("Rajesh");
    else if (i==5) printf("Howard");
    return;
}


int main()
{
    long long n;
    scanf("%lld", &n);

    int giatri=1;
    int socs=1;
    while (n>socs)
    {
        n=n-socs;        // printf("%lld ", n);
        giatri=giatri+1;
        if (giatri>5)
        {
            socs=socs*2;
            giatri=1;
        }
    }                   // printf("\n");


    //printf("gia tri %d  n = %lld\n", giatri, n);
    chuyen(giatri);
    return 0;
}
