#include<stdio.h>
#include<math.h>

/*long dem(long n)
{
    long a[10];
    long sl=0;
    while (n>0)
    {
        a[sl]=n %10;
        n=n /10;
        sl++;
    }

    long d=0;
    for (long i=0; i<sl; i++)
    {
        if (a[i]==0)
        {
            d=d+1;
        }
    }
    return d;
}*/

int main()
{
    long n, k;
    scanf("%d%d", &n, &k);
    //printf("%d", dem(n));


    /*for (long i=n; i<1000000000; i=i+n)
    {
        if (i % n ==0 && dem(i)==k)
        {
            printf("%d", i);
            break;
        }
    }*/

    long kq=n;
    for (long i=0; i<k; i++)
    {
        kq=kq*10;
    }
    while (kq%n!=0)
    {
        kq=kq*10;
    }
    printf("%d", kq);
    return 0;
}
