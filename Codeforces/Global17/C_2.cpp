#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k, x;

ll tinh(ll n)
{
    if (n<=k) return n*(n+1)/2;
    ll res=k*(k+1)/2;
    n-=k;
    res+=(k-1+k-n)*n/2;
    return res;
}

void solve()
{
    cin>>k>>x;
    ll l=0, r=2*k-1;
    while (l+1<r)
    {
        ll mid=(l+r)/2;
        if (x>tinh(mid)) l=mid;
        else r=mid;
    }
    cout<<r<<endl;
}

int main()
{
    ll t;
    t=1; cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
