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

ll n, w[200005];
vector<tuple<ll, ll, ll>> edges;

struct DSU
{
    vector<ll> par, size, mx;
    ll n;
    DSU(){}
    DSU(ll _n)
    {
        n=_n;
        par.resize(n+5, 0);
        mx.resize(n+5, 0);
        for (ll i=1; i<=n; i++) par[i]=i;
        for (ll i=1; i<=n; i++) mx[i]=w[i];
        size.resize(n+5, 1);
    }
    ll find(ll u)
    {
        if (u==par[u]) return u;
        return par[u]=find(par[u]);  
        }
    bool merge(ll u, ll v)
    {
        u=find(u);
        v=find(v);
        if (u==v) return false;
        if (size[u]<size[v]) swap(u, v);
        par[v]=u;
        mx[u]=max(mx[u], mx[v]);
        size[u]+=size[v];
        return true;
    }
    bool same_component(ll u, ll v)
    {
        return find(u)==find(v);
    }
};

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>w[i];
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v; cin>>u>>v;
        edges.push_back({w[u], u, v});
    }
    sort(edges.begin(), edges.end());
    ll ans=0;
    DSU dsu(n);
    for (auto [w, u, v]: edges)
    {
        ans+=w+dsu.mx[dsu.find(v)];
        dsu.merge(u, v);
    }
    cout<<ans;
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