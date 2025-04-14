#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

void solve()
{
    ll n; cin>>n;
    ll a[n+5], b[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i]>>b[i];
    ll ans=-1;
    for (ll i=0; i<=n; i++)
    {
        ll cnt=0;
        for (ll j=1; j<=n; j++) if (a[j]<=i && i<=b[j]) ++cnt;
        if (cnt==i) ans=i;
    }
    cout<<ans;
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