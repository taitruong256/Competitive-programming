/*==============================================================================================================
         __                    __                                             _____     ______    _______
        |  |                  |  |                                           /  __ \   / _____|  / ______|     
      __|  |__              __|  |__                                         |_|  | |  | |       | |  
     |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
        |  |    _____   _     |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
        |  |_  | |_| | | |    |  |_  | |   | |_| | | |_| | | |  | | | |_| |    / /___   ____| |  | |___| |
        \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  |_| \____ |   |______| |______/  \_______/
                                                                        | |
                                                                      __/ |
                                                                     |___/  
                             Nothing is impossible, only you think it is impossible                 
                                     Try, try, try again until you succeed     
                                        Pratice, practice, and practice
                                       Where is your bug, delete it there
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define ll long long
//tree<ll, null_type, less<ll>, rb_tree_tag,
//tree_order_statistics_node_update> T;             //find_by_order            order_of_key
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e14;
const ll maxn = (1<<20)+5;
ll dp[maxn][21];

void solve()
{
    ll n; cin>>n;
    ll a[n+5][n+5];
    for (ll i=0; i<n; i++)
      for (ll j=0; j<n; j++) cin>>a[i][j];

    for (ll i=0; i<(1<<n); i++)
        for (ll j=0; j<n; j++) dp[i][j]=inf;
    for (ll i=0; i<n; i++) dp[(1<<i)][i]=0;

    for (ll mask=0; mask<(1<<n); mask++)
    {
      for (ll u=0; u<n; u++) if (mask&(1<<u)) 
      {
        ll old_mask=mask^(1<<u);   
        for (ll v=0; v<n; v++) if (old_mask&(1<<v) && u!=v)
        {   
          dp[mask][u]=min(dp[old_mask][v]+a[v][u], dp[mask][u]);
        }
      }
    }

    ll ans=inf;
    for (ll i=0; i<n; i++) ans=min(ans, dp[(1<<n)-1][i]);
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    // #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}