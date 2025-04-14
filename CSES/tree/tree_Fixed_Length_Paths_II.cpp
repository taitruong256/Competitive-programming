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
vector<ll> adj[200005];
ll n, x, y, cnt[200005], sz[200005], ans, mx_depth;
bool process[200005];

struct fenwick
{
    ll n; 
    vector<ll> bit;

    fenwick(){}
    fenwick(ll _n)
    {
        n=_n;
        bit.resize(n+5);
    }

    void update(ll idx, ll val)
    {
        ++idx;
        for (ll i=idx; i<=n; i+=-i&i) bit[i]+=val;
    }

    ll query(ll idx)
    {
        ++idx;
        ll sum=0;
        for (ll i=idx; i>0; i-=-i&i) sum+=bit[i];
        return sum;
    }

    ll query(ll l, ll r)
    {
        if (l>r) return 0;
        return query(r)-query(l-1);
    }
};
fenwick ft(200000);

ll get_subtree_size(ll u, ll par)
{
    sz[u]=1;
    for (auto v: adj[u]) if (v!=par && process[v]==false) 
        sz[u]+=get_subtree_size(v, u);
    return sz[u];
}

ll get_centroid(ll u, ll par, ll s)
{         
    for (auto v: adj[u]) if (v!=par && process[v]==false && sz[v]>s/2) 
        return get_centroid(v, u, s);
    return u;
}

void get_cnt(ll u, ll par, bool flag, ll depth)
{
    if (depth>y) return;     
    mx_depth=max(mx_depth, depth);
    if (flag==true) ft.update(depth, 1);
    else ans+=ft.query(max(0, x-depth), y-depth);
    for (auto v: adj[u]) if (process[v]==false && v!=par) get_cnt(v, u, flag, depth+1);    
}

void centroid_decomposition(ll u)
{
    ll centroid=get_centroid(u, -1, get_subtree_size(u, -1)); 
    process[centroid]=true;
    mx_depth=0;
    cnt[0]=1;
    for (auto v: adj[centroid]) if (process[v]==false)
    {
        get_cnt(v, centroid, false, 1);   
        get_cnt(v, centroid, true, 1);   
    } 
    for (ll i=1; i<=mx_depth; i++) ft.update(i, -ft.query(i, i));
    for (auto v: adj[centroid]) if (process[v]==false) centroid_decomposition(v);
}

struct LCA
{
    vector<vector<ll>> adj;
    vector<ll> height, euler, first, tree;
    vector<bool> visited;
    ll n, m;

    LCA () {}

    LCA (vector<vector<ll>> _adj, ll root=1)
    {
        adj=_adj;
        n=adj.size();
        height.resize(n+5); 
        first.resize(n+5);
        visited.resize(n+5);
        dfs(1, 0);
        m=euler.size();
        tree.resize(4*m+5);
        build(1, 0, m-1);    //luu y index cua euler tour bat dau tu 0
    }

    void dfs(ll u, ll h)
    {
        visited[u]=true;
        height[u]=h;
        first[u]=euler.size();
        euler.push_back(u);
        for (auto v: adj[u]) if (visited[v]==false)
        {
            dfs(v, h+1);
            euler.push_back(u);
        }
    }

    void build(ll id, ll l, ll r)
    {
        if (l==r) 
        {
            tree[id]=euler[l];
            return;
        }
        ll mid=(l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        ll left=tree[id*2], right=tree[id*2+1];
        tree[id]=(height[left]<height[right])?left:right;
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return -1;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        ll left=query(id*2, l, mid, u, v);
        ll right=query(id*2+1, mid+1, r, u, v);
        if (left==-1) return right;
        if (right==-1) return left;
        return (height[left]<height[right])?left:right;
    }

    ll lca(ll u, ll v)
    {
        ll left=first[u], right=first[v];
        if (left>right) swap(left, right);
        return query(1, 0, m-1, left, right);
    }
};

void solve()
{
    cin>>n>>x>>y;
    for (ll i=1; i<n; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ft.update(0, 1);
    centroid_decomposition(1);
    cout<<ans;
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