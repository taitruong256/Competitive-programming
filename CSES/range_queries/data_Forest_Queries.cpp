/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
         __                    __
        |  |                  |  |         
     ___|  |__             ___|  |__  
    |__ |   __|           |__ |   __| 
        |  |    ____    _     |  |    ____  __  __  ____    _____    _____
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \
        |  |_  | |_| | | |    |  |   | |   | \_/ | | |_| | | /  \ | | |_| |
        \____\ \____/| |_|    \__\   |_|   \_____/ \_____/ |_|  | | \__   |
                                                                        | |
                                                                      __/ |
                                                                     |___/  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll int
const ll mod = 1e9+7;
const ll inf = 1e9;

void solve()
{
    ll n, q; cin>>n>>q;
    char a[n+5][n+5];
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) cin>>a[i][j];

    ll dp[n+5][n+5];
    memset(dp, 0, sizeof(dp));
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+(a[i][j]=='*');
    
    while (q--)
    {
        ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
        cout<<dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1]<<endl;
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