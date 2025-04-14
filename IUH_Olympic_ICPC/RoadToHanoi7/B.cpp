#include<stdio.h>


int chuki(int n)
{
    if (n%6==0) return 5;
    else return n%6-1;
}

int main()
{
    long long x, y, n, t;
    scanf("%lld%lld%lld", &x, &y, &n);
    long long a[]={x, y, y-x, -x, -y, x-y};


    printf("%lld", (a[chuki(n)]+1000000007)%1000000007);
    return 0;
}
