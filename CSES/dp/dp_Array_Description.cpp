/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const ll mod = 1e9+7;

void solve()
{
    ll n, m; cin>>n>>m;
    ll a[n+5], dp[n+5][m+5];
    memset(dp, 0, sizeof(dp));
    for (ll i=1; i<=n; i++) cin>>a[i];
    if (a[1]==0)
        for (ll i=1; i<=m; i++) dp[1][i]=1;
    else 
        dp[1][a[1]]=1;
    
    for (ll i=2; i<=n; i++)
    {
        if (a[i]==0)
            for (ll j=1; j<=m; j++) dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%mod;
        else 
            dp[i][a[i]]=(dp[i-1][a[i]-1]+dp[i-1][a[i]]+dp[i-1][a[i]+1])%mod;
    }

    // for (ll i=1; i<=n; i++)
        // for (ll j=1; j<=m; j++) cout<<dp[i][j]<<" \n"[j==m];
    ll ans=0;
    for (ll i=1; i<=m; i++) ans=(ans+dp[n][i])%mod;
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}