#include<stdio.h>

int main()
{
    long long n, k;
    scanf("%lld%lld", &n, &k);  //printf("%lld %lld\n", n, k);

    long long t=n;
    while (t%10==0) t=t/10;

    for (long long i=0; i<k; i++) t=t*10;
    while (t%n!=0)
        t=t*10;
    printf("%lld", t);
    return 0;
}
