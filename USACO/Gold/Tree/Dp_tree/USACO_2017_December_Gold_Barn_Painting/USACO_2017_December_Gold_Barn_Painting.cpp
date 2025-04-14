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
#define ll long long
#define endl '\n'
const ll inf = 1e18;
const ll mod = 1e9+7;

void setIO(string s)
{
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}
ll n, k, dp[100005][5];
vector<ll> adj[100000];

void dfs(ll u, ll p)
{
    for (auto v: adj[u]) if (v!=p)
    {
        dfs(v, u);
        dp[u][1]=dp[u][1]*(dp[v][2]+dp[v][3]);
        dp[u][2]=dp[u][2]*(dp[v][1]+dp[v][3]);
        dp[u][3]=dp[u][3]*(dp[v][1]+dp[v][2]);
        dp[u][1]%=mod;
        dp[u][2]%=mod;
        dp[u][3]%=mod;
    }
}

void solve()
{
    setIO("barnpainting");
    cin>>n>>k;
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (ll i=1; i<=n; i++) dp[i][1]=dp[i][2]=dp[i][3]=1;
    for (ll i=1; i<=k; i++)
    {
        ll p, c; cin>>p>>c;
        dp[p][1]=dp[p][2]=dp[p][3]=0;
        dp[p][c]=1;
    }
    dfs(1, -1);
    cout<<(dp[1][1]+dp[1][2]+dp[1][3])%mod;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}