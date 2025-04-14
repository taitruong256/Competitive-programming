#include<stdio.h>

int main()
{
    long long t;
    scanf("%lld", &t);
    for (int i=0; i<t; i++)
    {
        long long a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        printf("%lld\n", (a+b*2+c*3)%2);
    }
    return 0;
}
