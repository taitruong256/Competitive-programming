#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve()
{
    ll n, k, d; cin>>n>>k>>d;
    ll a[n];
    for (ll i=0; i<n; i++) cin>>a[i];
    map<ll, ll> count;
    for (ll i=0; i<d; i++) ++count[a[i]];
    ll ans=count.size();
    for (ll i=d; i<n; i++)
    {
        ++count[a[i]];
        --count[a[i-d]];
        if (count[a[i-d]]==0) count.erase(a[i-d]);
        ans=min(ans, (ll)count.size());
    }
    cout<<ans<<endl;
}

int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("a_input.txt","r",stdin);
    freopen("a_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}
