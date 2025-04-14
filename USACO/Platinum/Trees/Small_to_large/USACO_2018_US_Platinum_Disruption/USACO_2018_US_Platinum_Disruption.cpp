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

void setIO(string s)
{
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}

ll n, m, ans[50005], par[50005][17], id[50005], depth[50005];
vector<pair<ll, ll>> adj[50005];
multiset<ll> paths[50005], removes[50005];

bool vis[50005];
void bfs(ll u)
{
    queue<ll> q;
    q.push(u);
    vis[u]=true;
    while (!q.empty())
    {
        ll u=q.front(); q.pop();      
        for (auto [v, i]: adj[u]) if (vis[v]==false)
        {
            q.push(v);
            vis[v]=true;
            depth[v]=depth[u]+1;
            id[v]=i;
            par[v][0]=u;
            for (ll i=1; i<=16; i++) par[v][i]=par[par[v][i-1]][i-1];
        }
    }
}

ll jump(ll u, ll n)
{
    for (ll i=16; i>=0; i--) if (n&(1LL<<i)) u=par[u][i];
    return u;
}

ll lca(ll u, ll v)
{
    if (depth[u]<depth[v]) swap(u, v);
    u=jump(u, depth[u]-depth[v]);
    if (u==v) return u;
    for (ll i=16; i>=0; i--) 
        if (par[u][i]!=par[v][i])
        {
            u=par[u][i];
            v=par[v][i];
        }
    return par[u][0];
}

void dfs2(ll u, ll p)
{
    for (auto [v, i]: adj[u]) if (v!=p) dfs2(v, u);
    for (auto [v, i]: adj[u]) if (v!=p)
    {
        if (paths[u].size()<paths[v].size()) swap(paths[u], paths[v]);
        for (auto x: paths[v]) paths[u].insert(x);
        if (paths[u].size()<paths[v].size()) cerr<<u<<" "<<"what\n";
    }
    for (auto x: removes[u]) 
    {
        if (paths[u].find(x)==paths[u].end()) cerr<<"olala\n";
        paths[u].erase(paths[u].find(x));
    }
    if (id[u]!=0) 
    {
        if (ans[id[u]]!=0) cerr<<"wow\n";
        if (paths[u].size()==0) ans[id[u]]=-1;
        else ans[id[u]]=*paths[u].begin();
    }
}

void solve()
{
    setIO("disrupt");
    cin>>n>>m;
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    for (ll i=1; i<=n; i++) vis[i]=false;
    bfs(1);
    for (ll i=1; i<=m; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        paths[u].insert(w);
        paths[v].insert(w);
        removes[lca(u, v)].insert(w);
        removes[lca(u, v)].insert(w);
    }
    for (ll i=1; i<=n; i++) vis[i]=false;
    dfs2(1, 0);
    for (ll i=1; i<=n-1; i++) cout<<ans[i]<<endl;
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