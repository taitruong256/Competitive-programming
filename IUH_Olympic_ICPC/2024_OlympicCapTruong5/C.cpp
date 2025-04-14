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
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
     Laziness is only temporary comfort. The future will regret that day. Don't fall into the trap of comfort.
                The most beautiful meeting in this world is meeting the best version of yourself.
                          Practice doing things you don't like but are useful to you
                                   Success is born from problem solving
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll n, q, t=0;
vector<ll> adj[100005];
ll a[100005], bit[100005], time_in[100005], time_out[100005];
bool vis[100005];
 
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

    ll opt(ll x, ll y)
    {
        return x+y;
    }

    void down(ll id, ll l, ll r)
    {
        ll mid=(l+r)/2;
        ll t=lazy[id];
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

void dfs(ll u)
{
    vis[u]=true;
    time_in[u]=++t;
    for (auto v: adj[u]) if (vis[v]==false) dfs(v);
    time_out[u]=t;
}
 
void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++)
    {
        ll u=i, v=1;
        if (i==1) cin>>a[i];
        else cin>>a[i]>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(vis, false, sizeof(vis));
    memset(bit, 0, sizeof(bit));
    dfs(1);
    segment_tree_lazy seg(n);
    for (ll i=1; i<=n; i++) seg.update(1, 1, n, time_in[i], time_in[i], a[i]);
 
    while (q--)
    {
        char t; cin>>t;
        if (t=='p')
        {
            ll x, k; cin>>x>>k;
            seg.update(1, 1, n, time_in[x]+1, time_out[x], k);
        }
        else 
        {
            ll x; cin>>x;
            cout<<seg.query(1, 1, n, time_in[x], time_in[x])<<endl;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}