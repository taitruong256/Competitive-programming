#include<stdio.h>

int main()
{
int t;
    scanf("%d", &t);
    while(t--)
    {
        long long a1, a2, a3;
        scanf("%lld%lld%lld", &a1, &a2, &a3);
        long long tb=(a1+a2+a3)%3;
        printf("%lld\n", tb);
    }
    return 0;
}
