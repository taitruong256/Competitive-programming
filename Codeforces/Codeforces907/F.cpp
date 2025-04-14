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
                                Hãy hoàn thành công việc một cách cẩu thả nhất
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;

ll q, sz[500005], depth[500005], par[500005], pos[500005], root[500005], tin[500005], timer=1, id=1, cur=1;
vector<ll> adj[500005];
struct query
{
    ll type, v, u;
};

struct segment_tree_lazy
{
    vector<ll> tree, lazy;
    ll n;

    segment_tree_lazy(){}
    void init(ll _n)
    {
        n=_n;
        tree.resize(0);
        lazy.resize(0);
        tree.resize(4*n+5);
        lazy.resize(4*n+5);
    }

    ll opt(ll x, ll y)
    {
        return x+y;
    }

    void down(ll id, ll l, ll r)
    {
        ll t=lazy[id];
        ll mid=(l+r)/2;
        tree[id*2]+=t*(mid-l+1);
        lazy[id*2]+=t;
        tree[id*2+1]+=t*(r-mid);
        lazy[id*2+1]+=t;
        lazy[id]=0;
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        down(id, l, r);
        return opt(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if (l>v || r<u) return;
        if (u<=l && r<=v) 
        {
            tree[id]+=val*(r-l+1);
            lazy[id]+=val;
            return;
        }
        ll mid=(l+r)/2;
        down(id, l, r);
        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, r, u, v, val);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
};
segment_tree_lazy seg_size, seg_sum;

void dfs_size(ll u, ll p)
{
    sz[u]=1;
    tin[u]=timer++;
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
    ll h_child=0;
    for (ll v: adj[u]) if (v!=p && sz[v]>sz[h_child]) h_child=v;
    if (h_child==0) return;
    dfs_hld(h_child, u, top);
    for (ll v: adj[u]) if (v!=p && v!=h_child) dfs_hld(v, u, v);
}

void update_path(ll u, ll v)
{
    if (depth[u]<depth[v]) swap(u, v);   
    while (root[u]!=root[v])
    {    
        seg_size.update(1, 1, cur, pos[root[u]], pos[u], 1);                  
        u=par[root[u]];        
    }                 
    if (depth[u]>depth[v]) swap(u, v);     
    seg_size.update(1, 1, cur, pos[u], pos[v], 1);                         
    // cout<<"type 1: "; for (ll i=1; i<=cur; i++) cout<<seg_size.query(1, 1, cur, pos[i], pos[i])<<" "; cout<<endl;  
}

void solve()
{
    cin>>q;
    id=1;
    cur=1;
    timer=1;
    vector<query> qry;
    seg_size.init(q+1);
    seg_sum.init(q+1);
    for (ll i=1; i<=q; i++)
    {
        ll type, v=0, x=0; cin>>type;
        if (type==1) cin>>v, x=cur+1;
        else cin>>v>>x;
        qry.push_back({type, v, x});
        if (type==1) 
        {
            adj[v].push_back(cur+1);
            ++cur;
        }
    }
   
    dfs_size(1, 0);
    dfs_hld(1, 0, 1);              
    seg_size.update(1, 1, cur, 1, 1, 1);
    for (auto [type, v, x]: qry)
    {
        if (type==1) update_path(x, 1);
        else 
        {
            seg_sum.update(1, 1, cur, tin[v], tin[v]+seg_size.query(1, 1, cur, pos[v], pos[v])-1, x);
            // cout<<"type 2: "; for (ll i=1; i<=cur; i++) cout<<seg_sum.query(1, 1, cur, i, i)<<" "; cout<<endl;  
        }
    }
    // for (ll i=1; i<=cur; i++) cout<<seg_size.query(1, 1, cur, i, i)<<" "; cout<<endl;
    for (ll i=1; i<=cur; i++) cout<<seg_sum.query(1, 1, cur, tin[i], tin[i])<<" "; cout<<endl;
    for (ll i=1; i<=q+1; i++) adj[i].clear();
    for (ll i=1; i<=q+1; i++) sz[i]=0;
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