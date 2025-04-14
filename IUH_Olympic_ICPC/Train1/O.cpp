#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    bool kt=false;
    for (long long i=2; i<=n+1; i++)
    {
        long long t=i, d=0;
        while (t%2==0)
        {
            d=d+t/2;
            t=t/2;
        }
        if (t>1) d=d+(t*(t-1))/2;
        if (d==n)
        {
            cout<<i<<endl;
            kt=true;
        }
    }
    if (kt==false) cout<<-1;
    return 0;
}
