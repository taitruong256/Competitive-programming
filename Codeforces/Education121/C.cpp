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
    ll h[205], k[205], ans[205];
    for (ll i=1; i<=n; i++) cin>>k[i];
    for (ll i=1; i<=n; i++) cin>>h[i];
    memset(ans, 0, sizeof(ans));
    for (ll i=1; i<=n; i++)
    {
        ll K=k[i];
        ll H=h[i];
        if (ans[K-H+1]>0)
            for (ll j=1; j<=H; j++) ans[K-H+j]=ans[K-H]+j;
        else    
            for (ll j=1; j<=H; j++) ans[K-H+j]=j;
    }
    //for (ll i=1; i<=k[n]; i++) cout<<ans[i]<<" "; cout<<endl;
    ll sum=0;
    for (ll i=1; i<=k[n]; i++) sum+=ans[i];
    cout<<sum<<endl;
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