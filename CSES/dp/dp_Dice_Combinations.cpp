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
    ll n; cin>>n;
    ll dp[n+5];
    memset(dp, 0, sizeof(dp));
    dp[0]=1;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=min(i, 1LL*6); j++) dp[i]=(dp[i]+dp[i-j])%mod;
    cout<<dp[n];
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