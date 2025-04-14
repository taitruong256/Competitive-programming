/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, k, z; cin>>n>>k>>z;
    ll a[n+5], dp[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    memset(dp, 0, sizeof(dp));
    for (ll i=1; i<=n; i++) dp[i]=dp[i-1]+a[i];
    ++k;
    ll ans=dp[k];
    for (ll j=1; j<=z; j++)
    {
        ll maxi=0;
        if (k-2*j<1) continue;
        for (ll i=1; i<=k-2*j; i++) maxi=max(maxi, a[i]+a[i+1]);
        ans=max(ans, dp[k-2*j]+maxi*j);
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}