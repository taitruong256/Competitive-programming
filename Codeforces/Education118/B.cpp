#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a[n+1];
    for (ll i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);
    for (ll i=1; i<=n/2; i++) cout<<a[i]<<" "<<a[0]<<endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}