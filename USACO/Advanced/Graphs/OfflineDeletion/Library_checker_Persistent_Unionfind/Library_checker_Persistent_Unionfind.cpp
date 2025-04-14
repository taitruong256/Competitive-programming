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

struct DSU
{
    vector<ll> par, size, stk;
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
        return find(par[u]);
        }
    bool merge(ll u, ll v)
    {
        u=find(u);
        v=find(v);
        if (u==v) return false;
        if (size[u]<size[v]) swap(u, v);
        par[v]=u;
        size[u]+=size[v];
        stk.push_back(v);
        return true;
    }
    bool same_component(ll u, ll v)
    {
        return find(u)==find(v);
    }
    void rollback(ll t)
    {
        while (stk.size()>t)
        {
            ll u=stk.back(); stk.pop_back();
            size[par[u]]-=size[u];
            par[u]=u;
        }
    }
};

struct query
{
    ll t, k, u, v;
};

ll n, q, ans[200005];
vector<ll> adj[200005];
query qry[200005];
bool vis[200005];
DSU dsu(200005);

void dfs(ll u)
{
    ll t=dsu.stk.size();
    if (qry[u].t==0) dsu.merge(qry[u].u, qry[u].v);
    else ans[u]=dsu.same_component(qry[u].u, qry[u].v);
    for (auto v: adj[u])
    {
        dfs(v);
    }
    dsu.rollback(t);
}

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=q; i++)
    {
        ll t, k, u, v; cin>>t>>k>>u>>v;
        ++k; ++u; ++v;
        adj[k].push_back(i);
        qry[i]={t, k, u, v};
    }

    dfs(0);
    for (ll i=1; i<=q; i++) if (qry[i].t==1) cout<<ans[i]<<endl;
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