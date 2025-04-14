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
#define ll long long
#define endl '\n'
const ll inf = 1e18;
const ll mod = 1e9+7;

void setIO(string s)
{
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}
ll n, a[2005];

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
        return par[u]=find(par[u]);
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

struct edge
{
    ll u, v, w;
};

bool comp(edge a, edge b)
{
    return a.w>b.w;
}

void solve()
{
    setIO("superbull");
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    DSU dsu(n);
    vector<edge> ve;
    for (ll i=1; i<=n-1; i++)
        for (ll j=i+1; j<=n; j++)
            ve.push_back({i, j, a[i]^a[j]});
    sort(ve.begin(), ve.end(), comp);
    ll ans=0;
    for (auto [u, v, w]: ve)
    {
        if (dsu.merge(u, v)==true) ans+=w;
    }   
    cout<<ans;
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