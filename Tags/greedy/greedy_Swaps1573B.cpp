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
    ll a[n+5], b[n+5], ind[2*n+10];
    for (ll i=1; i<=n; i++) 
    {
       cin>>a[i];
       ind[a[i]]=i;
    }
    for (ll i=1; i<=n; i++) 
    {
        cin>>b[i];
        ind[b[i]]=i;
    }

    ll ans=1e11, res=1e11;
    for (ll i=2; i<=2*n; i+=2)
    {
        res=min(res, ind[i-1]);
        ans=min(ans, ind[i]+res);
    }
    cout<<ans-2<<endl;
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