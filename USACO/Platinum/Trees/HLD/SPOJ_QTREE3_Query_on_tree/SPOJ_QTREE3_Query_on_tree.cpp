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
vector<vector<ll>> adj(100005);
vector<ll> nod(100005);

struct segment_tree
{
    vector<ll> tree;
    ll n;

    segment_tree(){}
    segment_tree(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
    }

    ll opt(ll x, ll y)
    {
        return max(x, y);
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return -1;
        if (u<=l && r<=v) 
        {
            if (tree[id]!=1) return -1;
            while (l!=r)
            {
                ll mid=(l+r)/2;
                if (tree[id*2]==1) id=id*2, r=mid;
                else id=id*2+1, l=mid+1;
            }
            return nod[l];
        }
        ll mid=(l+r)/2;
        ll left=query(id*2, l, mid, u, v);
        ll right=query(id*2+1, mid+1, r, u, v);
        if (left!=-1) return left;
        return right;
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
    segment_tree seg;

    HLD(){}
    HLD(ll _n, vector<vector<ll>> _adj, vector<ll> _val)
    {
        n=_n;
        adj=_adj;
        val=_val;   if ((ll)val.size()<n) cerr<<"Số lượng phần tử của vector val <n.\n";
        seg=segment_tree(n);
        sz.resize(n+5); depth.resize(n+5); par.resize(n+5); pos.resize(n+5); root.resize(n+5); 
        dfs_size(1, 0);
        dfs_hld(1, 0, 1);
    }

    ll opt(ll x, ll y)
    {
        if (y!=-1) return y;
        return x;
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
        nod[id]=u;
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

    void update(ll u)
    {
        val[u]=1-val[u];
        seg.update(1, 1, n, pos[u], val[u]);
    }

    ll query_path(ll u, ll v)
    {
        if (depth[u]<depth[v]) swap(u, v);    
        ll ans=-1;
        while (root[u]!=root[v])
        {                         
            ans=opt(ans, seg.query(1, 1, n, pos[root[u]], pos[u])); 
            u=par[root[u]];        
        }                 
        if (depth[u]>depth[v]) swap(u, v);                    
        ans=opt(ans, seg.query(1, 1, n, pos[u], pos[v]));  
        return ans;
    }

    ll query(ll u)
    {
        return query_path(1, u);
    }
};

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> val(n+5, 0);
    HLD hld(n, adj, val);
    while (q--)
    {
        ll type, u; cin>>type>>u;
        if (type==0) hld.update(u);
        else cout<<hld.query(u)<<endl;
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