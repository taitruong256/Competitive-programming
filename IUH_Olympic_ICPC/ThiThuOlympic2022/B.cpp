#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll tongchuso(ll n)
{
    ll s=0;
    if (n<0) return 2e9;
    while (n>0)
    {
        s+=n%10;
        n/=10;
    }
    return s;
}

bool check(ll x, ll n)
{
    x-=100000;
    ll d=x*(x+tongchuso(x));
    return d>=n;
}

void solve()
{
    ll n; cin>>n;
    ll l=1, r=6e9, ans=-1;

    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (check(mid, n)==true) ans=mid, r=mid-1;
        else l=mid+1;
    }

    for (ll i=ans-100000; i<=ans; i++) if (i*(i+tongchuso(i))==n)
    {
        cout<<i;
        return;
    }
    cout<<-1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    solve();
    return 0;
}
