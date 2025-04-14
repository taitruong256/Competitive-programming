#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, l, r; cin>>n>>l>>r;
    ll a[n+1];
    for (ll i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);
    ll ans=0;
    for (ll i=1; i<=n; i++) 
        ans+=upper_bound(a+i+1, a+n+1, r-a[i])-lower_bound(a+i+1, a+n+1, l-a[i]);
    cout<<ans<<"\n";
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
