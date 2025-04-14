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
vector<pair<ll, pair<ll, ll>>> adj[200005];

struct HLD
{
    ll n, id=1;
    vector<ll> sz, depth, par, pos, root, edges, tree, weight;

    HLD(){}
    HLD(ll _n)
    {
        n=_n;
        sz.resize(n+5); 
        depth.resize(n+5); 
        par.resize(n+5); 
        pos.resize(n+5); 
        root.resize(n+5); 
        edges.resize(n+5); 
        tree.resize(4*n+5);
        weight.resize(n+5, -1e18);
        dfs_size(1, 0);
        dfs_hld(1, 0, 1);
    }

    ll opt(ll x, ll y)
    {
        return max(x, y);
    }

    ll seg_query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        return opt(seg_query(id*2, l, mid, u, v), seg_query(id*2+1, mid+1, r, u, v));
    }

    void seg_update(ll id, ll l, ll r, ll pos, ll v)
    {
        if (l>pos || r<pos) return;
        if (pos<=l && r<=pos) 
        {
            tree[id]=v;
            return;
        }
        ll mid=(l+r)/2;
        seg_update(id*2, l, mid, pos, v);
        seg_update(id*2+1, mid+1, r, pos, v);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }

    void dfs_size(ll u, ll p)
    {
        sz[u]=1;
        depth[u]=depth[p]+1;
        par[u]=p;
        for (auto [v, w]: adj[u]) if (v!=p)
        {
            edges[w.second]=v;
            weight[v]=w.first;
            dfs_size(v, u);
            sz[u]+=sz[v];
        }
    }

    void dfs_hld(ll u, ll p, ll top)
    {
        pos[u]=id++;
        root[u]=top;
        seg_update(1, 1, n, pos[u], weight[u]);
        ll h_child=0;
        for (auto [v, w]: adj[u]) if (v!=p && sz[v]>sz[h_child]) h_child=v;
        if (h_child==0) return;
        dfs_hld(h_child, u, top);
        for (auto [v, w]: adj[u]) if (v!=p && v!=h_child) dfs_hld(v, u, v);
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

    void update(ll i, ll v)
    {
        weight[edges[i]]=v;
        ll u=edges[i];
        seg_update(1, 1, n, pos[u], v);
    }

    ll query_path(ll u, ll v)
    {
        if (depth[u]<depth[v]) swap(u, v);    
        ll ans=INT_MIN;
        while (root[u]!=root[v])
        {                         
            ans=opt(ans, seg_query(1, 1, n, pos[root[u]], pos[u]));
            u=par[root[u]];        
        }                 
        if (depth[u]>depth[v]) swap(u, v);                    
        ans=opt(ans, seg_query(1, 1, n, pos[u]+1, pos[v]));
        return ans;
    }

    ll query(ll u, ll v)
    {
        ll l=LCA(u, v);     
        ll ans=opt(query_path(u, l), query_path(v, l));
        return ans;
    }
};

void solve()
{
    ll n; cin>>n;
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v, {w, i}});
        adj[v].push_back({u, {w, i}});
    }
    HLD hld(n);
    while (true)
    {
        string s; cin>>s;
        if (s=="QUERY")
        {
            ll u, v; cin>>u>>v;
            cout<<hld.query(u, v)<<endl;
        }
        else if (s=="CHANGE")
        {
            ll u, v; cin>>u>>v;
            hld.update(u, v);
        }
        else break;
    }
    for (ll i=1; i<=n; i++) adj[i].clear();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}