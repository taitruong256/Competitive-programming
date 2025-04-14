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
                             Nothing is impossible, only you think it is impossible                 
                                     Try, try, try again until you succeed     
                                        Pratice, practice, and practice
                                       Where is your bug, delete it there
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
ll parent[200005][21];
vector<ll> adj[200005], time_in, time_out, chieucao;
ll ti;

struct node{ll val, lazy;};
struct segment_lazy
{
    vector<node> tree;
    ll n;

    segment_lazy(){}
    segment_lazy(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
        buildtree(1, 1, n);
    }

    void buildtree(ll id, ll l, ll r)
    {
        if (l==r)
        {
            tree[id].val=chieucao[time_in[l]];
            tree[id].lazy=0;
            return;
        }
        ll mid=(l+r)/2;
        buildtree(id*2, l, mid);
        buildtree(id*2+1, mid+1, r);
        tree[id].val=max(tree[id*2].val, tree[id*2+1].val);
    }

    void down(ll id)
    {
        ll t=tree[id].lazy;
        tree[id*2].val+=t;
        tree[id*2].lazy+=t;
        tree[id*2+1].val+=t;
        tree[id*2+1].lazy+=t;
        tree[id].lazy=0;
    }

    void updatetree(ll id, ll l, ll r, ll u, ll v, ll k)
    {
        if (r<u || l>v) return;
        if (l>=u && r<=v)
        {
            tree[id].val+=k;
            tree[id].lazy+=k;
            return;
        }
        ll mid=(l+r)/2;
        down(id);
        updatetree(id*2, l, mid, u, v, k);
        updatetree(id*2+1, mid+1, r, u, v, k);
        tree[id].val=max(tree[id*2].val, tree[id*2+1].val);
    }

    ll getvalue(ll id, ll l, ll r, ll u, ll v)
    {
        if (r<u || l>v) return -1e9;
        if (l>=u && r<=v) return tree[id].val;
        ll mid=(l+r)/2;
        down(id);
        return max(getvalue(id*2, l, mid, u, v), getvalue(id*2+1, mid+1, r, u, v));
    }

    ll getpos(ll id, ll l, ll r, ll val)
    {
        if (l==r) return l;
        ll mid=(l+r)/2;
        down(id);
        if (tree[id*2].val==val) return getpos(id*2, l, mid, val);
        else return getpos(id*2+1, mid+1, r, val);
    }
};


void dfs(ll u, ll par)
{
    time_in[u]=++ti;
    for (auto v: adj[u]) if (v!=par) 
    {
        chieucao[v]=chieucao[u]+1;
        dfs(v, u);
    }
    time_out[u]=ti;
}

ll query(ll x, ll y)
{
    for (ll i=0; i<21; i++) if (y&(1<<i)) x=parent[x][i];
    return x;
}

void solve()
{
    ll n, k; cin>>n>>k;
    time_in.resize(n+5);
    time_out.resize(n+5);
    chieucao.resize(n+5);

    for (ll i=2; i<=n; i++)
    {
        ll x; cin>>x; 
        adj[i].push_back(x);
        adj[x].push_back(i);
        parent[i][0]=x;
    }

    for (ll j=1; j<21; j++)
        for (ll i=1; i<=n; i++) parent[i][j]=parent[parent[i][j-1]][j-1];
    

    ti=0;
    chieucao[1]=0;
    dfs(1, 0);
    segment_lazy seg(n);
    // for (ll i=1; i<=4*n; i++) cout<<seg.tree[i].val<<" "; cout<<endl;
    // for (ll i=1; i<=n; i++) cout<<time_in[i]<<" "<<time_out[i]<<endl;
    // for (ll i=1; i<=n; i++) cout<<chieucao[i]<<" "; cout<<endl;
    // cout<<seg.getvalue(1, 1, n, 1, n)<<endl;
    // cout<<seg.getpos(1, 1, n, 5)<<endl;
    // for (ll i=0; i<=2; i++)
    // {
    //     for (ll j=1; j<=n; j++) cout<<parent[j][i]<<" "; cout<<endl;
    // }
    for (ll i=1; i<=n; i++) cout<<seg.getvalue(1, 1, n, i, i)<<" "; cout<<endl;
    while (k--)
    {
        ll mx=seg.getvalue(1, 1, n, 1, n);
        ll pos=seg.getpos(1, 1, n, mx);
        pos=query(pos, (mx-1)/2);  cout<<pos<<endl;
        seg.updatetree(1, 1, n, time_in[pos], time_out[pos], -mx/2);        
        for (ll i=1; i<=n; i++) cout<<seg.getvalue(1, 1, n, i, i)<<" "; cout<<endl;
    }
    cout<<seg.getvalue(1, 1, n, 1, n)<<endl;

    for (ll i=1; i<=n; i++) adj[i].clear();
    time_in.clear();
    time_out.clear();
    chieucao.clear();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}