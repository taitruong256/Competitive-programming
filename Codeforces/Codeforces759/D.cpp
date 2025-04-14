#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n; 
    ll a[n+1], b[n+1];
    for (ll i=0; i<n; i++) 
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b, b+n);
    ll d=0;
    for (ll i=0; i<n; i++) if (a[i]!=b[i]) ++d;
    if (d%3==0) cout<<"YES\n"; else cout<<"NO\n";
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
