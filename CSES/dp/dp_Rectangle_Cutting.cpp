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
#define inf 1e9

void solve()
{
    ll n, m; cin>>n>>m;
    ll dp[505][505];
    for (ll i=0; i<505; i++)
        for (ll j=0; j<505; j++) dp[i][j]=1e9;
    for (ll i=0; i<505; i++) dp[i][i]=0;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++)
        {
            for (ll k=1; k<i; k++) dp[i][j]=min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
            for (ll k=1; k<j; k++) dp[i][j]=min(dp[i][j], dp[i][j-k]+dp[i][k]+1);
        }

    // for (ll i=1; i<=n; i++)
        // for (ll j=1; j<=m; j++) cout<<dp[i][j]<<" \n"[j==m];
    cout<<dp[n][m];
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