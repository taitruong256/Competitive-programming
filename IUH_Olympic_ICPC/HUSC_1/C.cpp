#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define cint int t; cin >> t; while(t--)
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int N = 1e5 + 9, MOD = 1e9 + 7;
void solve() {
    ll n; cin>>n;
    map<ll, pair<char, ll>> dichuyen;
    for (ll i=1; i<=n; i++)
    {
        ll x; cin>>x;
        char c; cin>>c;;
        ll y; cin>>y;
        dichuyen[x]={c, y};
    }
    ll pos; cin>>pos;
    for (ll i=1; i<=n; i++)
    {
        auto [c, y]=dichuyen[pos];
        if (c=='L') pos-=y;
        else pos+=y;
    }
    cout<<pos;
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