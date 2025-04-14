#include<stdio.h>
#include<algorithm>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        long long a[3];
        scanf("%lld%lld%lld", &a[0], &a[1], &a[2]);
        std::sort(a, a+3);

    }
    return 0;
}
