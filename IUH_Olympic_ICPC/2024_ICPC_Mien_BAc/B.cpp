#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll n, dp[10005];
vector<tuple<ll, ll, ll>> a;

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++)
    {
        ll x, y, z; cin>>x>>y>>z;
        a.push_back({x, y, z});
    }
    a.push_back({1e18, 1e18, 1e18});
    sort(a.begin(), a.end(), greater<tuple<ll, ll, ll>>());
    // for (auto [x, y, z]: a) cout<<x<<" "<<y<<" "<<z<<endl;
    auto [x ,y, z]=a[1];
    dp[1]=z;
    for (ll i=2; i<=n; i++)
    {
        auto [x1, y1, z1]=a[i];
        ll mx=0;
        for (ll j=1; j<=i-1; j++) 
        {
            auto [x2, y2, z2]=a[j];
            if (x2>=x1 && y2>=y1) mx=max(mx, dp[j]);
        }
        dp[i]+=mx+z1;
    }
    // for (ll i=1; i<=n; i++) cout<<dp[i]<<" "; cout<<endl;
    ll ans=0;
    for (ll i=1; i<=n; i++) ans=max(ans, dp[i]);
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