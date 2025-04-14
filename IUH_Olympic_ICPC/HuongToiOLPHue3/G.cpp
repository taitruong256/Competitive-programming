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
                                       Where is the bug, delete it there
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
vector<pair<ll, ll>> adj2[80005];
vector<ll> adj[80005];
ll par[80005], val[80005], sz[80005], depth[80005], pos[80005], root[80005], id=1;

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
        return x+y;
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
segment_tree_faster seg(80005);


ll opt(ll x, ll y)
{
    return max(x, y);
}

void dfs_par(ll u, ll p)
{
    for (auto [v, w]: adj2[u]) if (v!=p)
    {
        val[v]=w;
        dfs_par(v, u);
    }
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
    ll ans=0;
    while (root[u]!=root[v])
    {                         
        cerr<<u<<" "<<v<<" "<<par[root[u]]<<" "<<par[root[v]]<<endl;
        ans=opt(ans, seg.query(pos[root[u]]+1, pos[u]));
        u=par[root[u]];        
    }                 
    if (depth[u]>depth[v]) swap(u, v);                    
    ans=opt(ans, seg.query(pos[u]+1, pos[v]));
    return ans;
}

ll query(ll u, ll v)
{
    ll l=LCA(u, v);
    ll ans=opt(query_path(u, l), query_path(v, l));
    ans-=val[l];
    return ans;
}

const int N = 1e5+5;
vector<int> E[N];

void solve()
{
    int n;
    cin >> n;
    for(int i=1; i<n;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj2[u].push_back({v, w});
        adj2[v].push_back({u, w});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs_par(1, 0);
    dfs_size(1, 0);
    dfs_hld(1, 0, 1);
    for (ll i=1; i<=n; i++) seg.update(pos[i], val[pos[i]]);

    
    for (ll i=1; i<=n; i++) cout<<pos[i]<<" "; cout<<endl;
    
    for (ll i=1; i<=n; i++) cout<<val[i]<<" "; cout<<endl;
    cout<<query_path(1, 4)<<endl;
    cout<<query_path(1, 3)<<endl;
    cout<<query_path(2, 4)<<endl;
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