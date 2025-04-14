#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve()
{
    ll n; cin>>n;
    ll a[n+5], index[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) index[a[i]]=i;

    ll r=n+1;
    for (ll i=n; i>=1; i--) if (index[i]<r)
    {
        for (ll j=index[i]; j<r; j++) cout<<a[j]<<" ";
        r=index[i];
    }
    cout<<"\n";
}
 
int main() 
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t; cin>>t; 
    while (t--) solve();
    return 0;
}