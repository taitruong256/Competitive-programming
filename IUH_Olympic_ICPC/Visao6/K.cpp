#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

struct segment_tree_faster
{
    vector<ll> tree;
    ll n;

    segment_tree_faster(){}
    segment_tree_faster(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
    }

    ll opt(ll x, ll y)
    {
        return x^y;
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        return opt(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll pos, ll v)
    {
        if (l>pos || r<pos) return;
        if (pos<=l && r<=pos) 
        {
            tree[id]=v;
            return;
        }
        ll mid=(l+r)/2;
        update(id*2, l, mid, pos, v);
        update(id*2+1, mid+1, r, pos, v);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
};

struct HLD
{
    ll n, id=1;
    vector<vector<ll>> adj; 
    vector<ll> sz, depth, par, pos, root, val;
    segment_tree_faster seg;

    HLD(){}
    HLD(ll _n, vector<vector<ll>> _adj, vector<ll> _val)
    {
        n=_n;
        adj=_adj;
        val=_val;   if ((ll)val.size()<n) cerr<<"Số lượng phần tử của vector val <n.\n";
        seg=segment_tree_faster(n);
        sz.resize(n+5); depth.resize(n+5); par.resize(n+5); pos.resize(n+5); root.resize(n+5);
        dfs_size(1, 0);
        dfs_hld(1, 0, 1);
    }

    ll opt(ll x, ll y)
    {
        return x^y;
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
        pos[u]=id++;
        root[u]=top;
        seg.update(1, 1, n, pos[u], val[u]);
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

    void update(ll node, ll v)
    {
        val[node]=v;
        seg.update(1, 1, n, pos[node], v);
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
        ans=opt(ans, seg.query(1, 1, n, pos[u], pos[v]));
        return ans;
    }

    ll query(ll u, ll v)
    {
        ll l=LCA(u, v);
        ll ans=opt(query_path(u, l), query_path(v, l));
        // ans=opt(ans, val[l]);            
        return ans;
    }
};

vector<vector<ll>> adj(100005);
vector<vector<tuple<ll, ll, ll>>> edges(100005);
vector<ll> val(100005);

ll n, q, par[100005], id[100005];

void dfs(ll u, ll p)
{
    par[u]=p;
    for (auto [v, i, w]: edges[u]) if (v!=p) 
    {
        id[i]=v;
        val[v]=w;
        dfs(v, u);
    }
}

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[u].push_back({v, i, w});
        edges[v].push_back({u, i, w});
    }
    dfs(1, 0);
    HLD hld(n, adj, val);
    // for (ll i=1; i<=n; i++) cout<<hld.pos[i]<<" "; cout<<endl;
    // for (ll i=1; i<=n; i++) cout<<hld.val[i]<<" "; cout<<endl;
    while (q--)
    {
        ll type; cin>>type;
        if (type==1)
        {
            ll p, x; cin>>p>>x;
            hld.update(id[p], x);
            // for (ll i=1; i<=n; i++) cout<<hld.val[i]<<" "; cout<<endl;
        }
        else 
        {
            ll u, v; cin>>u>>v;
            ll ans=hld.query(u, v);
            cout<<ans<<endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}