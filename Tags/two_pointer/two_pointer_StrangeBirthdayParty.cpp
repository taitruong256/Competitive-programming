#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, m; cin>>n>>m;
    ll a[n+5], b[m+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=m; i++) cin>>b[i];
    sort(a+1, a+n+1, greater<ll>());
    ll j=1, ans=0;
    b[m+1]=1000000005;
    for (ll i=1; i<=n; i++)
    {
        if (b[j]<b[a[i]]) ans+=b[j++];
        else ans+=b[a[i]];  
    }
    cout<<ans<<"\n";
}

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}
