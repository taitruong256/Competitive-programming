#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n, d=0;
    cin>>n;
    while (n>0)
    {
        if (n%10==0 || n%10==1) ++d;
        else break;
        n=n/10;
    }
    cout<<d;
    return 0;
}
