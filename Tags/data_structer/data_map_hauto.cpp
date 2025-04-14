#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve()
{
    ll n, m; cin>>n>>m;
    ll a[n+1], dp[n+2];
    set<ll> s;
    for (ll i=1; i<=n; i++) cin>>a[i];
    dp[n+1]=0;
    for (ll i=n; i>=1; i--) 
    {
        s.insert(a[i]);
        dp[i]=s.size();
    }
    for (ll i=1; i<=m; i++) 
    {
        ll x; cin>>x;
        cout<<dp[x]<<"\n";
    }
}
 
int main() 
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
    return 0;
}