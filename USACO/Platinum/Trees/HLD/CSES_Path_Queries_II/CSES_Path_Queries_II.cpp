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
#define ll int
#define endl '\n'
const ll mod = 1e9+7;
vector<vector<ll>> adj(200005);
 
struct segment_tree_faster
{
    ll n;
    vector<ll> tree;
    segment_tree_faster(){}
    segment_tree_faster(ll _n)
    {
        n=_n;
        tree.resize(2*n+5);
    }
    ll opt(ll x, ll y)
    {
        return max(x, y);
    }
    ll query(ll l, ll r)
    {
        ll ans=0;
        for (l+=n, r+=n; l<=r; l>>=1, r>>=1) 
        {
            if (l&1) ans=opt(ans, tree[l++]);
            if (!(r&1)) ans=opt(ans, tree[r--]);
        }
        return ans;
    }
    void update(ll i, ll val)
    {
        tree[i+=n]=val;
        for (i/=2; i>0; i/=2) tree[i]=opt(tree[i*2], tree[i*2+1]);
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
        return max(x, y);
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
        seg.update(pos[u], val[u]);
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
        seg.update(pos[node], v);
    }

    ll query_path(ll u, ll v)
    {
        if (depth[u]<depth[v]) swap(u, v);    
        ll ans=INT_MIN;
        while (root[u]!=root[v])
        {                         
            ans=opt(ans, seg.query(pos[root[u]], pos[u]));
            u=par[root[u]];        
        }                 
        if (depth[u]>depth[v]) swap(u, v);                    
        ans=opt(ans, seg.query(pos[u], pos[v]));
        return ans;
    }

    ll query(ll u, ll v)
    {
        ll l=LCA(u, v);
        ll ans=opt(query_path(u, l), query_path(v, l));
        ans=opt(ans, val[l]);
        return ans;
    }
};

void solve()
{
    ll n, q;
    cin>>n>>q;
    vector<ll> val(n+5);
    for (ll i=1; i<=n; i++) cin>>val[i];
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    HLD hld(n, adj, val);
    while (q--)
    {
        ll type; cin>>type;
        if (type==1)
        {
            ll u, v; cin>>u>>v;
            hld.update(u, v);
        }
        else 
        {
            ll u, v; cin>>u>>v;  
            cout<<hld.query(u, v)<<" ";
        }
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