#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const ll mod = 1e9+7;
const ll inf = 1e9;
ll fac[1000005], rev[1000005];

ll binpow(ll a, ll n, ll mod)
{
    if (n==0) return 1;
    ll temp=binpow(a, n/2, mod);
    if (n%2==0) return temp*temp%mod;
    else return temp*temp%mod*a%mod;
}

void solve()
{
    ll n, k; cin>>n>>k;
    cout<<fac[n]*rev[k]%mod*rev[n-k]%mod<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    fac[0]=rev[0]=1;
    for (ll i=1; i<=1000000; i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
        rev[i]=binpow(fac[i], mod-2, mod);
    }
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}