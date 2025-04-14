#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define cint int t; cin >> t; while(t--)
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int N = 1e5 + 9, MOD = 1e9 + 7;



void solve() {
    ll k; cin>>k;
    string s; cin>>s;
    ll n, m; cin>>n>>m;
    ll deg=m;
    for (ll i=1; i<=m; i++)
    {
        ll u, v; cin>>u>>v;
    }
    for (ll i=0; i<m; i++)
    {
        if (deg==n-1)
        {
            if (s[i%k]=='1')
            {
                cout<<2<<endl;
                return;
            }
            else 
            {
                cout<<1<<endl;
                return;
            }
        }
        --deg;
    }
}
signed main () {
    ios
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}