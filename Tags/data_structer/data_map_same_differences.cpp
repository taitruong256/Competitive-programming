#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, s=0; cin>>n; 
    ll a[n+1];
    map<ll, ll> count;
    count.clear();
    ll ans=0;
    for (ll i=0; i<n; i++)
    {
        cin>>a[i];
        ans+=count[a[i]-i];
        ++count[a[i]-i];
    }
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
