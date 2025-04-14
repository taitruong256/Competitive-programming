#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";
 
void solve()
{
    ll n; cin>>n;
    ll a[n];
    for (ll i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);
    ll ans=0;
    for (ll s=2; s<=n*2; s++)
    {
        ll l=0, r=n-1, now=0; 
        while (l<r) 
            if (a[l]+a[r]==s) {++now; ++l, --r;}
            else if (a[l]+a[r]>s) --r;
            else ++l;
        ans=max(ans, now);
    }
    cout<<ans<<endl;
}
 
int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}