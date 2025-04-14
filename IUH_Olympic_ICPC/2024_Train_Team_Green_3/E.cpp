#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll binpow(ll x, ll n, ll mod)
{
    ll ans=1;
    while (n>0)
    {
        if (n%2==1) ans=(ans*x)%mod;
        x=(x*x)%mod;
        n/=2;
    }
    return ans;
}

void solve()
{
    ll t; cin>>t;
    ll n[t+5], k[t+5];
    for (ll i=1; i<=t; i++) cin>>n[i];
    for (ll i=1; i<=t; i++) cin>>k[i];
    for (ll i=1; i<=t; i++)
    {
        if (n[i]==k[i]) cout<<1<<endl;
        else cout<<binpow(2, k[i], mod)<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}