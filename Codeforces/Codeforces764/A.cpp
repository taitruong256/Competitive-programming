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
    ll n; cin>>n;
    ll a[n+1];
    ll mx=0, mi=1e9+5;
    for (ll i=0; i<n; i++) cin>>a[i];
    for (ll i=0; i<n; i++) mi=min(mi, a[i]);
    for (ll i=0; i<n; i++) mx=max(mx, a[i]);
    cout<<mx-mi<<endl;
}
 
int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  cin>>t;
    while (t--) solve();
    return 0;
}
