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
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    ll ans=0;
    for (ll i=0; i<32; i++)
    {
        ll cnt=0;
        for (ll j=1; j<=n; j++) cnt+=a[j]>>i&1;
        ans=__gcd(ans, cnt);
    }         
    for (ll i=1; i<=n; i++) if (ans%i==0) cout<<i<<" ";
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  cin>>t;
    while (t--) solve();
    return 0;
}