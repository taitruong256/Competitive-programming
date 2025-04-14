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
#define ll int
const ll inf = 1e9;
int dp[1000005];

void solve()
{
    ll n, x; cin>>n>>x;
    ll c[n+5];
    for (ll i=1; i<=n; i++) cin>>c[i];
    dp[0]=0;
    for (ll i=1; i<=x; i++) dp[i]=inf;

    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=x; j++)
            if (j>=c[i]) dp[j]=min(dp[j-c[i]]+1, dp[j]);
    if (dp[x]==inf) dp[x]=-1;
    cout<<dp[x];
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