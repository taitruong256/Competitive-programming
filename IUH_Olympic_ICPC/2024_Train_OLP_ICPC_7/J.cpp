#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

void solve()
{
    ll n, s; cin>>n>>s;
    ll a[105], mx=0;
    for (ll i=1; i<=n; i++)
    {
        cin>>a[i];
        mx=max(mx, a[i]);
    }
    mx*=s;
    if (mx%1000==0) cout<<mx/1000;
    else cout<<mx/1000+1;
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