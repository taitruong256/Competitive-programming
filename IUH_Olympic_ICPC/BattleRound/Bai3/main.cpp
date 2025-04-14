#include<stdio.h>

void chuyen(long long n, long long i)
{
    long long t=n/i;
    if (0*t<n && n<1*t-1) printf("Sheldon");
    else if (1*t<n && n<2*t-1) printf("Leonard");
    else if (2*t<n && n<3*t-1) printf("Penny");
    else if (3*t<n && n<4*t-1) printf("Rajesh");
    else if (4*t<n && n<5*t-1) printf("Howard");
}

int main()
{
    long long n;
    scanf("%lld", &n);
    long long m=5, i=1;
    if (n<=5) chuyen(n, i);
    else
    {
        while (n>m)
        {
            n=n-m;
            m=m*2;
            i=i*2;   //so luong chu so giong nhau
        }
        chuyen(n, i);
    }

    return 0;
}
