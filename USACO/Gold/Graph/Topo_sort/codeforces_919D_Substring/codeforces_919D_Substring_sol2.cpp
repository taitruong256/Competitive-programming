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
                                          Noi dau + Suy ngam = Tien bo 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
ll n, m, dp[300005][30];
char c[300005];
vector<ll> adj[300005], rev_adj[300005], topo;
ll vis[300005];

bool dfs(ll u)
{
    vis[u]=1;
    for (auto v: adj[u]) 
    {
        if (vis[v]==0) dfs(v);
        if (vis[v]==1) return false;
    }
    vis[u]=2;
    topo.push_back(u);
    return true;
}

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=n; i++) cin>>c[i];
    while (m--)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
    }
    for (ll i=1; i<=n; i++) if (vis[i]==0) 
    {
        if (dfs(i)==false)
        {
            cout<<-1;
            return;
        }
    }
    reverse(topo.begin(), topo.end());
    for (int u: topo)
    {
        ++dp[u][c[u]-'a'+1];
        for (int v: adj[u])
        {
            for (ll i=1; i<=26; i++) 
                dp[v][i]=max(dp[v][i], dp[u][i]);
        }
    }
    ll ans=0;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=26; j++) ans=max(ans, dp[i][j]);
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