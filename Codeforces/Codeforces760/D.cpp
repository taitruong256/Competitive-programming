#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, k; cin>>n>>k;
    ll a[n+1];
    for (ll i=0; i<n; i++) cin>>a[i];
    sort(a, a+n, greater<ll>());
    ll ans=0, l=0;
    for (ll i=0; i<k; i++) ans+=a[i+k]/a[i];
    for (ll i=2*k; i<n; i++) ans+=a[i];
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
