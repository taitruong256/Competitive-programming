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
const ll maxn = (1<<20);
ll dp[maxn][20];
vector<ll> adj[20];
bool vis[maxn][20];

void solve()
{
    ll n, m; cin>>n>>m;
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        --u; --v;
        adj[u].push_back(v);
    }

    dp[1][0]=true;
    vis[1][0]=true;
    queue<pair<ll, ll>> q;
    q.push({1, 0});
    while (!q.empty())
    {
        ll u=q.front().second;
        ll mask=q.front().first;
        q.pop();
        for (auto v: adj[u])
        {
            if (!(mask&(1<<v))) 
            {
                ll new_mask=mask^(1<<v);
                dp[new_mask][v]+=dp[mask][u];
                dp[new_mask][v]%=mod;
                if (vis[new_mask][v]==false)
                {
                    q.push({new_mask, v});
                    vis[new_mask][v]=true;
                }
            }
        }
    }
    cout<<dp[(1<<n)-1][n-1];
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