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
ll n, q;
vector<ll> adj[100005];

struct segment_tree_lazy
{
    vector<ll> tree, lazy;
    ll n;
    segment_tree_lazy(){}
    segment_tree_lazy(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
        lazy.resize(4*n+5);
    }
    ll opt(const ll &x, const ll &y)
    {
        return x+y;
    }
    void down(const ll &id, const ll &l, const ll &r)
    {
        ll t=lazy[id];
        ll mid=(l+r)/2;
        tree[id*2]+=t*(mid-l+1);
        lazy[id*2]+=t;
        tree[id*2+1]+=t*(r-mid);
        lazy[id*2+1]+=t;
        lazy[id]=0;
    }
    ll query(const ll &id, const ll &l, const ll &r, const ll &u, const ll &v)
    {
        if (u>v) return 0;
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        down(id, l, r);
        return opt(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
    }
    void update(const ll &id, const ll &l, const ll &r, const ll &u, const ll &v)
    {
        if (u>v) return;
        if (l>v || r<u) return;
        if (u<=l && r<=v) 
        {
            tree[id]+=r-l+1;
            lazy[id]+=1;
            return;
        }
        ll mid=(l+r)/2;
        down(id, l, r);
        update(id*2, l, mid, u, v);
        update(id*2+1, mid+1, r, u, v);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
};

struct HLD
{
    ll n, id=1;
    vector<ll> sz, depth, par, pos, root;
    segment_tree_lazy seg;

    HLD(){}
    HLD(ll _n)
    {
        n=_n;
        seg=segment_tree_lazy(n);
        sz.resize(n+5); depth.resize(n+5); par.resize(n+5); pos.resize(n+5); root.resize(n+5);
        dfs_size(1, 0);
        dfs_hld(1, 0, 1);
    }

    ll opt(const ll &x, const ll &y)
    {
        return x+y;
    }

    void dfs_size(const ll &u, const ll &p)
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

    void dfs_hld(const ll &u, const ll &p, const ll &top)
    {
        pos[u]=id++;
        root[u]=top;
        ll h_child=0;
        for (ll v: adj[u]) if (v!=p && sz[v]>sz[h_child]) h_child=v;
        if (h_child==0) return;
        dfs_hld(h_child, u, top);
        for (ll v: adj[u]) if (v!=p && v!=h_child) dfs_hld(v, u, v);
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

    void update_path(ll u, ll v)
    {
        if (depth[u]<depth[v]) swap(u, v);
        while (root[u]!=root[v])
        {
            seg.update(1, 1, n, pos[root[u]], pos[u]);
            u=par[root[u]];
        }
        if (depth[u]>depth[v]) swap(u, v);
        seg.update(1, 1, n, pos[u]+1, pos[v]);
    }

    void update(ll u, ll v)
    {
        ll l=LCA(u, v);
        update_path(u, l);
        update_path(v, l);
    }

    ll query_path(ll u, ll v)
    {
        if (depth[u]<depth[v]) swap(u, v);    
        ll ans=0;
        while (root[u]!=root[v])
        {                         
            ans=opt(ans, seg.query(1, 1, n, pos[root[u]], pos[u]));
            u=par[root[u]];        
        }                 
        if (depth[u]>depth[v]) swap(u, v);                    
        ans=opt(ans, seg.query(1, 1, n, pos[u]+1, pos[v]));
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
    setIO("grassplant");
    cin>>n>>q;
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> v(n+5);
    HLD hld(n);
    while (q--)
    {
        char c; cin>>c;
        ll u, v; cin>>u>>v;
        if (c=='P') hld.update(u, v);
        else cout<<hld.query(u, v)-1<<endl;
    }
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