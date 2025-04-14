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

ll n, m, q, par[200005][25], d[200005], mx[200005][25], sum=0;
vector<ll> adj[200005];
vector<tuple<ll, ll, ll>> edges;

struct DSU
{
    vector<ll> par, size;
    ll n;
    DSU(){}
    DSU(ll _n)
    {
        n=_n;
        par.resize(n+5, 0);
        for (ll i=1; i<=n; i++) par[i]=i;
        size.resize(n+5, 1);
    }
    ll find(ll u)
    {
        if (u==par[u]) return u;
        return par[u]=find(par[u]);   //neu co rollback thi return find(par[u]);
        }
    bool merge(ll u, ll v)
    {
        u=find(u);
        v=find(v);
        if (u==v) return false;
        if (size[u]<size[v]) swap(u, v);
        par[v]=u;
        size[u]+=size[v];
        return true;
    }
    bool same_component(ll u, ll v)
    {
        return find(u)==find(v);
    }
};

bool comp(tuple<ll, ll, ll> a, tuple<ll, ll, ll> b)
{
    auto [x1, y1, z1]=a;
    auto [x2, y2, z2]=b;
    return z1<=z2;
}

void dfs(ll u, ll p)
{
    for (auto v: adj[u]) if (v!=p)
    {
        par[v][0]=u;
        mx[v][0]=w;
        d[v]=d[u]+1;
        dfs(v, u);
    }
}

ll lift(ll u, ll k)
{
    for (ll i=0; i<20; i++) if (k&(1LL<<i)) u=par[u][i];
    return u;
}

ll LCA(ll u, ll v)
{
    if (d[u]<d[v]) swap(u, v);
    u=lift(u, d[u]-d[v]);
    if (u==v) return u;
    for (ll i=19; i>=0; i--) if (lift(u, 1LL<<i)!=lift(v, 1LL<<i))
    {
        u=lift(u, 1LL<<i);
        v=lift(v, 1LL<<i);
    }
    return par[u][0];
}

ll query(ll u, ll lca)
{
    ll depth=d[u]-d[lca];
    ll ans=0;
    for (ll i=19; i>=0; i--) if (depth&(1LL<<i))
    {
        ans=max(ans, mx[u][i]);
        u=par[u][i];
    }
    return ans;
}

void solve()
{
    cin>>n;
    for (ll i=0; i<n-1; i++)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for (ll k=1; k<20; k++)
        for (ll i=1; i<=n; i++)
        {
            par[i][k]=par[par[i][k-1]][k-1];
            mx[i][k]=max(mx[i][k-1], mx[par[i][k-1]][k-1]);
        }

    cin>>q;
    while (q--)
    {
        ll u, k; cin>>u>>k;
        ll 
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
