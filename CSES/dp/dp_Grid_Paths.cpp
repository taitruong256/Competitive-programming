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

void solve()
{
    ll n; cin>>n;
    char c[n+5][n+5];
    memset(c, '.', sizeof(c));
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) cin>>c[i][j];
    
    ll dp[n+5][n+5];
    memset(dp, 0, sizeof(dp));
    dp[1][1]=1;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++)
        {
            if (c[i-1][j]=='.') dp[i][j]+=dp[i-1][j];
            if (c[i][j-1]=='.') dp[i][j]+=dp[i][j-1];
            if (c[i][j]=='*') dp[i][j]=0;
            dp[i][j]%=(1000000007);
        }
    // for (ll i=1; i<=n; i++)
        // for (ll j=1; j<=n; j++) cout<<dp[i][j]<<" \n"[j==n];
    cout<<dp[n][n];
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