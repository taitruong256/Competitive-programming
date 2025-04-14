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
ll n, root;
vector<ll> adj[100005], adj2[100005];

struct Centroid_Decomposition
{
    ll n, LOG;
    vector<vector<ll>> jump;
    vector<ll> par, sz, depth, res;
    vector<bool> vis;

    Centroid_Decomposition(){}
    Centroid_Decomposition(ll _n)
    {
        n=_n;
        LOG=ceil(log2(n));
        jump.resize(n+5); par.resize(n+5); sz.resize(n+5); depth.resize(n+5); res.resize(n+5, 1e18); vis.resize(n+5);
        for (ll i=0; i<=n; i++) jump[i].resize(LOG+2);
        dfs_dist(1, 0);
        build(1, 0);
    }

    void dfs_dist(ll u, ll p)
    {
        jump[u][0]=p;
        depth[u]=depth[jump[u][0]]+1;
        for (ll i=1; i<=LOG; i++) jump[u][i]=jump[jump[u][i-1]][i-1];
        for (ll v: adj[u]) if (v!=p) dfs_dist(v, u);
    }

    ll lca(ll u, ll v)
    {
        if (depth[u]<depth[v]) swap(u, v);
        for (ll i=LOG; i>=0; i--) if ((depth[u]-depth[v])&(1LL<<i)) u=jump[u][i];
        if (u==v) return u;
        for (ll i=LOG; i>=0; i--) if (jump[u][i]!=jump[v][i]) u=jump[u][i], v=jump[v][i];
        return jump[u][0];
    }

    ll dist(ll u, ll v)
    {
        return depth[u]+depth[v]-2*depth[lca(u, v)];
    }

    void dfs_size(ll u, ll p)
    {
        sz[u]=1;
        for (ll v: adj[u]) if (v!=p && vis[v]==false)   //luu y them vis[v]==false neu khong MLE
        {
            dfs_size(v, u);
            sz[u]+=sz[v];
        }
    }

    ll centroid(ll u, ll p, ll s)
    {
        for (auto v: adj[u]) if (v!=p && vis[v]==false && sz[v]*2>s) return centroid(v, u, s);   //luu y them vis[v]==false neu khong MLE
        return u;
    }

    void build(ll u, ll p)
    {
        dfs_size(u, p);
        ll c=centroid(u, p, sz[u]);
        par[c]=p;
        vis[c]=true;
        if (p!=0)
        {
            adj2[c].push_back(p);
            adj2[p].push_back(c);
        }
        if (p==0) root=c;
        for (auto v: adj[c]) if (v!=p && vis[v]==false) build(v, c);
    }

    void update(ll u)
    {
        ll v=u;
        while (u!=0)
        {
            res[u]=min(res[u], dist(u, v));
            u=par[u];
        }
    }

    ll query(ll u)
    {
        ll ans=1e18, v=u;
        while (u!=0)
        {
            ans=min(ans, res[u]+dist(u, v));
            u=par[u];
        }
        return ans;
    }
};

ll depth[100005];

void dfs(ll u, ll p)
{
    depth[u]=depth[p]+1;
    for (auto v: adj2[u]) if (v!=p) dfs(v, u);
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Centroid_Decomposition cd(n);
    dfs(root, 0);
    for (ll i=1; i<=n; i++) cout<<char('A'+depth[i]-1)<<" ";
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