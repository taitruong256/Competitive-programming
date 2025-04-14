#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll dist(ll x1, ll y1, ll x2, ll y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

void solve()
{
    ll x, y, x1, y1, x2, y2; cin>>x>>y>>x1>>y1>>x2>>y2;
    ll ans=1e18;
    for (ll i=x1; i<=x2; i++)
        for (ll j=y1; j<=y2; j++)
            ans=min(ans, dist(i, j, x, y));
    cout<<fixed<<setprecision(3)<<sqrt(ans);
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