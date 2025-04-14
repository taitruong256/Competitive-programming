#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n; cin>>n;
    long long a[n+1], gtmax=-1000000, d=1;
    for (long long i=0; i<n; i++) cin>>a[i];
    for (long long i=1; i<n; i++)
    {
        if (a[i-1]<=a[i]) gtmax=max(gtmax, d++);
        else d=1;
    }
    cout<<gtmax;
    return 0;
}
