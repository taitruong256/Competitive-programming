#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(nullptr);
#define ll long long
using namespace std;

void solve()
{
    ll n, m; cin>>n>>m;
    map<ll, ll> d1, d2;
    for (ll i=0; i<m; i++)
    {
        ll x; cin>>x;
        ++d1[x];
        ++d2[d1[x]];
        if (d2[d1[x]]==n) cout<<1; else cout<<0;
    }
}

int main() {                   
    FAST;
    //reopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
    return 0;
}
