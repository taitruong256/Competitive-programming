#include<stdio.h>
#include<algorithm>

using namespace std;


int comp(const int a, const int b){
   return a > b;
}


int main()
{
    long long t;
    scanf("%lld", &t);
    while (t--)
    {
        long long n;
        scanf("%lld", &n);
        long long a[n+1];
        for (long long i=0; i<n; i++) scanf("%lld", &a[i]);

        std::sort(a, a+n);

        long long gtmax=a[0];
        for (long long i=0; i<n-1; i++)
        {
            a[i]=a[i+1]-a[i];
            if (a[i]>gtmax) gtmax=a[i];
        }

        printf("%lld\n", gtmax);
    }
    return 0;
}
