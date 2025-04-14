#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, s=0; cin>>n; 
    ll pos[n+1];
    for (ll i=1; i<=n; i++)
    {
        ll x; cin>>x;
        pos[x]=i;
    }
    ll l=n+1, r=0;
    for (ll i=1; i<=n; i++)
    {
        l=min(l, pos[i]);
        r=max(r, pos[i]);
        if (r-l+1==i) cout<<"1"; else cout<<"0";
    }
    cout<<"\n";
}

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}
