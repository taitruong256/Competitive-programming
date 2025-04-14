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
ll n, q;
vector<vector<ll>> adj(200005);

struct HLD
{
    ll n, id=0;
    vector<vector<ll>> adj; 
    vector<ll> sz, depth, par, pos, root, val;
    HLD(){}
    HLD(ll _n, vector<vector<ll>> _adj, vector<ll> _val)
    {
        n=_n;
        adj=_adj;
        val=_val;
        sz.resize(n+5); depth.resize(n+5); par.resize(n+5); pos.resize(n+5); root.resize(n+5);
        dfs_size(1, 0);
        dfs_hld(1, 0, 1);
    }

    void dfs_size(ll u, ll p)
    {
        sz[u]=1;
        depth[u]=depth[p]+1;
        par[u]=p;
        for (ll v: adj[u]) if (v!=p)
        {
            dfs_size(v, u);
            sz[u]+=sz[v];
        }
    }

    void dfs_hld(ll u, ll p, ll top)
    {
        pos[u]=++id;
        root[u]=top;
        ll mx=-1;
        for (ll v: adj[u]) if (v!=p && (mx==-1 || sz[v]>mx)) mx=v;
        if (mx!=-1) dfs_hld(mx, u, top);
        for (ll v: adj[u]) if (v!=p && v!=mx) dfs_hld(v, u, v);
    }

    ll LCA(ll u, ll v)
    {
        while (root[u]!=root[v])
        {
            if (depth[root[u]]<depth[root[v]]) swap(u, v);
            u=par[root[u]];
        }
        if (depth[u]>depth[v]) swap(u, v);
        return u;
    }
};

void solve()
{
    cin>>n>>q;
    for (ll i=2; i<=n; i++)
    {
        ll p; cin>>p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    vector<ll> v(n+5);
    HLD hld(n, adj, v);
    while (q--)
    {
        ll u, v; cin>>u>>v;
        cout<<hld.LCA(u, v)<<endl;
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