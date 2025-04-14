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

ll sqr(ll x)
{
    return x*x;
}

ll dist(pair<ll, ll> a, pair<ll, ll> b)
{
    return sqr(a.first-b.first)+sqr(a.second-b.second);
}

struct edge
{
    ll u, v, w; 
};
vector<edge> E;

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

bool comp(edge a, edge b)
{
    return a.w<b.w;
}

ll n;
pair<ll, ll> p[100005], last[15];

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>p[i].first>>p[i].second;
    sort(p+1, p+n+1);
    
    for (ll i=0; i<=10; i++) last[i]={-1LL, -1LL};
    for (ll i=1; i<=n; i++)
    {
        for (ll j=0; j<=10; j++) if (last[j]!=make_pair(-1LL, -1LL))
            E.push_back({i, last[j].first, dist(p[i], {last[j].second, j})});
        last[p[i].second]={i, p[i].first};
    }

    //kruskal
    ll ans=0;
    sort(E.begin(), E.end(), comp);
    DSU dsu(n);
    for (auto [u, v, w]: E)
    {
        if (dsu.merge(u, v)==true) ans+=w;
    }
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