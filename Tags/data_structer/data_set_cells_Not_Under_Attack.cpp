#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(nullptr);
#define ll long long
using namespace std;

void solve()
{
    ll n, m; cin>>n>>m;
    set<ll> column, row;
    for (ll i=0; i<m; i++)
    {
        ll x, y; cin>>x>>y;
        column.insert(x);
        row.insert(y);
        cout<<(n-column.size())*(n-row.size())<<" ";
    }
}

int main() {                   
    FAST;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
    return 0;
}
