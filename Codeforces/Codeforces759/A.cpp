#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n; 
    ll a[n+1];
    ll ans=1;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) if (a[i]==1) ++ans;
    for (ll i=2; i<=n; i++) if (a[i]==1 && a[i-1]==1) ans+=4;
    for (ll i=2; i<=n; i++) if (a[i]==0 && a[i-1]==0)
    {
        ans=-1;
        break;
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
