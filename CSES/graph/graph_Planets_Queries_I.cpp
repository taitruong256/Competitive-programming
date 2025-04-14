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
const ll inf = 1e9;
ll dp[200005][31];

void solve()
{
    ll n, m; cin>>n>>m;   
    
    for (ll i=1; i<=n; i++) cin>>dp[i][0];

    for(int j = 1; j < 31; j++)
        for(int i = 1; i <= n; i++)
            dp[i][j] = dp[dp[i][j-1]][j-1];

    for (ll i=1; i<=n; i++)
    {
        for (ll j=0; j<=16; j++) cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    
    while (m--)
    {
        ll x, k; cin>>x>>k;
        for (ll i=0; i<30; i++) if (k&(1<<i)) x=dp[x][i];
        cout<<x<<endl;
    }
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