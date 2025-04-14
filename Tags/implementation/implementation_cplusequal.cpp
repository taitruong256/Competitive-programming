#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t; cin>>t;
    while (t--)
    {
        long long a, b, n, d=0;
        cin>>a>>b>>n;
        while (!(a>n || b>n))
        {
            ++d;
            if (a<b) a=a+b; else b=a+b;
        }
        cout<<d<<endl;
    }
    return 0;
}
