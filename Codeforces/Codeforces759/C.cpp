#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, k; cin>>n>>k; 
    ll a[n+1];
    for (ll i=0; i<n; i++) cin>>a[i];

    ll ans=0, d=0;
    sort(a, a+n);
    ll i=0;
    while (i<n)
    {
        ll gtmax=0;
        for (ll j=i; j<i+k; j++) if (abs(a[j])>gtmax) gtmax=abs(a[j]);
        if (i+k<=n) ans+=2*gtmax;
        else ans+=gtmax;
        i=i+k;
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
