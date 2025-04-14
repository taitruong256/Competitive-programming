#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define cint int t; cin >> t; while(t--)
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int N = 1e5 + 9, MOD = 1e9 + 7;
void solve() {
    ll n; cin>>n;
    ll a[n+5], ans=0;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll val=0; val<=501; val++)
    {
        ll mx=0, sum=0;
        for (ll i=1; i<=n; i++) 
        {
            sum+=a[i];
            mx=max(mx, a[i]);
            if (mx>val || sum<0) 
            {
                sum=0;
                mx=0;
            }
            ans=max(ans, sum-mx);
        }
    }
    cout<<ans;
}
signed main () {
    ios
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}