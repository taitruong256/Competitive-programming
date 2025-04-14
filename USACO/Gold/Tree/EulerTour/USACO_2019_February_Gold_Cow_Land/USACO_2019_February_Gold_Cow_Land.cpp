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
const ll inf = 1e18;
const ll mod = 1e9+7;

void setIO(string s)
{
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}

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
        for (ll i=idx; i<=n; i+=-i&i) bit[i]^=val;
    }

    ll query(ll idx)
    {
        ll sum=0;
        for (ll i=idx; i>0; i-=-i&i) sum^=bit[i];
        return sum;
    }
};

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

ll n, a[100005], q, time_in[100005], time_out[100005], timer=0;
vector<vector<ll>> adj(100005);

void euler_tour(ll u, ll p=-1)
{
    time_in[u]=++timer;
    for (auto v: adj[u]) if (v!=p) euler_tour(v, u);
    time_out[u]=timer;
}

void solve()
{
    setIO("cowland");
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v; cin>>u>>v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    euler_tour(1);
    fenwick ft(n);
    LCA lca(adj);
    for (ll i=1; i<=n; i++) 
    {
        ft.update(time_in[i], a[i]);
        ft.update(time_out[i]+1, a[i]);
    }
    while (q--)
    {
        ll type; cin>>type;
        if (type==1) 
        {
            ll pos, val; cin>>pos>>val;
            ft.update(time_in[pos], a[pos]);
            ft.update(time_out[pos]+1, a[pos]);
            a[pos]=val;
            ft.update(time_in[pos], a[pos]);
            ft.update(time_out[pos]+1, a[pos]);
        }
        else 
        {
            ll l, r; cin>>l>>r;
            ll x=lca.lca(l, r);
            cout<<(ft.query(time_in[l])^ft.query(time_in[r])^a[x])<<endl;
        }
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