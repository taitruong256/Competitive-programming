#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n; 
    vector<ll> a(n+1);
    for (ll i=0; i<n; i++) cin>>a[i];
    
    ll d=0, t=a[n-1];
    for (ll i=n-2; i>=0; i--) if (a[i]>t)
    {
        ++d;
        t=a[i];
    }
    cout<<d<<"\n";
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
