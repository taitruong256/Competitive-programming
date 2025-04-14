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
    ll n, m; cin>>n>>m;
    ll price[n+5], page[n+5];
    for (ll i=1; i<=n; i++) cin>>price[i];
    for (ll i=1; i<=n; i++) cin>>page[i];

    ll dp[m+5];
    memset(dp, 0, sizeof(dp));
    for (ll i=1; i<=n; i++)
        for (ll j=m; j>=0; j--) if (j>=price[i]) dp[j]=max(dp[j], dp[j-price[i]]+page[i]);
    cout<<dp[m];
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