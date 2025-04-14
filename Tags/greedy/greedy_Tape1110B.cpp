/*=====================================================================================
    Nothing is impossible, only you think it is impossible                 
            Try, try, try again until you succeed     
              Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, m, k; cin>>n>>m>>k;
    ll a[n+5], d[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<n; i++) d[i]=a[i+1]-a[i];   
    sort(d+1, d+n);   
    ll ans=0;
    for (ll i=1; i<=n-k; i++) ans+=d[i];
    ans+=k; 
    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; // cin>>t;
    while (t--) solve();
    return 0;
}