#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, s=0; cin>>n; 
    ll a[n+1];
    for (ll i=0; i<n; i++) 
    {
        cin>>a[i];
        s=s+a[i];
    }
    if (2*s%n!=0) 
    {
        cout<<0<<"\n";
        return;
    }
    ll k=2*s/n, ans=0;
    map<ll, ll> count;
    count.clear();
    for (ll i=0; i<n; i++)
    {
        ans+=count[k-a[i]];
        ++count[a[i]];
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
