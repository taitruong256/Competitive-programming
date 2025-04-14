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
    sort(a+1, a+n+1);
    ll sum=0;
    for (ll i=1; i<=n; i++) sum+=a[i];  

    ll ans=sum;
    for (ll i=2; i<=n; i++) 
        for (ll j=1; j<=a[i]; j++) if (a[i]%j==0)
            ans=min(ans, sum-a[1]-a[i]+a[1]*j+a[i]/j);
    
    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  //cin>>t;
    while (t--) solve();
    return 0;
}