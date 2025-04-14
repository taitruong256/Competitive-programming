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
    ll dp[n+5][n+5], sum[n+5][n+5], a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i], dp[i][i]=a[i], sum[i][i]=a[i];
    for (ll i=1; i<=n-1; i++)
        for (ll j=i+1; j<=n; j++) sum[i][j]=sum[i][j-1]+a[j];

    for (ll i=n-1; i>=1; i--)
        for (ll j=i+1; j<=n; j++) 
            if (i+1==j) dp[i][j]=max(a[i], a[i+1]);
            else dp[i][j]=max(a[i]+sum[i+1][j]-dp[i+1][j], sum[i][j-1]-dp[i][j-1]+a[j]);
    cout<<dp[1][n];
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