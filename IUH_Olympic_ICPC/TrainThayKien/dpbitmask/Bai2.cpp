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
                                        Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define endl '\n'
const ll mod = 1e9+7;
const ll maxn = (1<<16)+5;
const ll inf = 1e9;
ll dp[maxn][16], n, a[16][16];
bool vis[maxn][16];

void solve()
{
    cin>>n;
    for (ll i=0; i<n; i++)
        for (ll j=0; j<n; j++) cin>>a[i][j];
    
    for (ll i=0; i<maxn; i++)
        for (ll j=0; j<n; j++)
        {
            dp[i][j]=inf;
            vis[i][j]=false;
        }
    for (ll i=0; i<n; i++) dp[1<<i][i]=0;

    queue<pair<ll, ll>> q;
    for (ll i=0; i<n; i++) q.push({1<<i, i}), vis[1<<i][i]=true;
    while (!q.empty())
    {
        ll mask=q.front().first;
        ll u=q.front().second;
        q.pop();
        for (ll v=0; v<n; v++) if (v!=u)
        {
            if (!(mask&(1<<v)))
            {
                ll new_mask=mask^(1<<v);
                dp[new_mask][v]=min(dp[new_mask][v], dp[mask][u]+a[u][v]);
                if (vis[new_mask][v]==false)
                {
                    q.push({new_mask, v});
                    vis[new_mask][v]=true;
                }
            }
        }
    }    
    ll ans=inf;
    for (ll i=0; i<n; i++) ans=min(ans, dp[(1<<n)-1][i]);
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}