#include<stdio.h>


int main()
{
    long long k, p, x;
    scanf("%lld%lld%lld", &k, &p, &x);
    float m=99999999.0;
    for (long long i=1; i<=k; i++)
    {
        if (x*i+1.0*k/i*p<m) m=x*i+1.0*k/i*p;
        //printf("%.3f        %.3f\n", x*i+k*1.0/i*p, m);
    }
    printf("%.3f", m);
    return 0;
}
