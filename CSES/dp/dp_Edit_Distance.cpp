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
    string s, t; cin>>s>>t;
    s=" "+s; t=" "+t;
    ll n=s.size()-1, m=t.size()-1;
    ll dp[n+5][m+5];
    for (ll i=0; i<=n; i++) dp[i][0]=i;
    for (ll i=0; i<=m; i++) dp[0][i]=i;

    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++)
        {
            if (s[i]==t[j]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
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