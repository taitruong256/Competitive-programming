#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";

void solve()
{
    ll n, k; cin>>n>>k;
    ll a[n], mx=0;
    map<ll, ll> count;
    for (ll i=0; i<n; i++)
    {
        cin>>a[i];
        if (a[i]%k==0) continue;
        ++count[k-a[i]%k];
        mx=max(mx, count[k-a[i]%k]);
    }
    ll ans=0;
    for (auto it: count) 
        if (it.second==mx) ans=k*(it.second-1)+it.first+1;
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
