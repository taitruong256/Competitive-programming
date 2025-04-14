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
const ll mod = 1e9+7;
ll n, m, q, depth[200005], par[200005][20], mx[200005][20];
vector<pair<ll, ll>> adj[200005];
bool vis[200005];

struct DSU
{
    vector<ll> par, size;
    ll n;

    DSU(){}
    DSU(ll _n)
    {
        n=_n;
        par.resize(n+5);
        for (ll i=1; i<=n; i++) par[i]=i;
        size.resize(n+5, 1);
    }

    ll find(ll u)
    {
        if (u==par[u]) return u;
        return par[u]=find(par[u]);
    }

    bool merge(ll u, ll v)
    {
        u=find(u);
        v=find(v);
        if (u==v) return false;
        if (size[u]<size[v]) swap(u, v);
        par[v]=u;
        size[u]+=size[v];
        return true;
    }

    bool same_component(ll u, ll v)
    {
        return find(u)==find(v);
    }
};

void dfs(ll u, ll p, ll c)
{  
    vis[u]=true;
    par[u][0]=p;
    mx[u][0]=c;
    for (ll i=1; i<20; i++) 
    {
        par[u][i]=par[par[u][i-1]][i-1];
        mx[u][i]=max(mx[u][i-1], mx[par[u][i-1]][i-1]);
    }
    for (auto [v, w]: adj[u]) if (vis[v]==false) 
    {
        depth[v]=depth[u]+1;
        dfs(v, u, w);
    }
}

pair<ll, ll> kthAcess(ll u, ll k)
{
    ll c=0*1LL;
    for (ll i=0; i<20; i++) if (k&(1<<i)) 
    {
        c=max(c, mx[u][i]);
        u=par[u][i];
    }
    return {u, c};
}

ll query(ll u, ll v)
{
    if (depth[u]<depth[v]) swap(u, v);
    auto [x, y]=kthAcess(u, depth[u]-depth[v]);
    u=x;
    ll c=y;
    if (u==v) return c;
    for (ll i=19; i>=0; i--) if (par[u][i]!=par[v][i])
    {
        c=max(c, mx[u][i]);
        c=max(c, mx[v][i]);
        u=par[u][i];
        v=par[v][i];
    }
    c=max(c, mx[u][0]);
    c=max(c, mx[v][0]);
    return c;
}

void solve()
{
    cin>>n>>m>>q;  
    DSU dsu(n);
    for (ll i=1; i<=m; i++)
    {
        ll u, v; cin>>u>>v;
        if (dsu.merge(u, v)==true) 
        {
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }
    }

    for (ll i=1; i<=n; i++) if (vis[i]==false) dfs(i, 0, 0);

    while (q--)
    {
        ll u, v; cin>>u>>v;
        if (u==v) cout<<0<<endl;
        else if (dsu.same_component(u, v)) cout<<query(u, v)<<endl;
        else cout<<-1<<endl;
    }
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