#include<stdio.h>

int main()
{
    long long n, m, a;
    scanf("%lld%lld%lld", &n, &m, &a);
    long long dai, rong;
    if (n%a==0) dai=n/a; else dai=n/a+1;
    if (m%a==0) rong=m/a; else rong=m/a+1;
    printf("%lld", dai*rong);
    return 0;
}
