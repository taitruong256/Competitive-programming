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
                                          Noi dau + Suy ngam = Tien bo 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
ll n, a[2005][2005];
vector<pair<ll, ll>> adj[2005];
bool vis[2005], ans=true;

struct edge
{
    ll u, v, w;
};
vector<edge> E;

bool comp(edge a, edge b)
{
    return a.w<b.w;
}

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

void dfs(ll u, ll par, ll src, ll dist)
{
    if (a[src][u]!=dist) ans=false;
    for (auto [v, w]: adj[u]) if (v!=par)
        dfs(v, u, src, dist+w);
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) cin>>a[i][j];

    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++)
        {
            if (i==j && a[i][j]!=0) {cout<<"NO"; return;};
            if (i!=j && a[i][j]==0) {cout<<"NO"; return;}
            if (a[i][j]!=a[j][i]) {cout<<"NO"; return;};
            if (i<j) E.push_back({i, j, a[i][j]});
        }
    sort(E.begin(), E.end(), comp);
    DSU dsu(n);
    for (auto [u, v, w]: E)
    {
        if (dsu.merge(u, v)==true) 
        {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }
    
    for (ll i=1; i<=n; i++) dfs(i, -1, i, 0);
    if (ans==true) cout<<"YES";
    else cout<<"NO";
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