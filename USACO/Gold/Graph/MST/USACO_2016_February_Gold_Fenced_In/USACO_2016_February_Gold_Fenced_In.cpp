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

void setIO(string s)
{
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}
ll A, B, n, m, a[2005], b[2005], cnt;

struct edge
{
    ll u, v, w;
    bool operator<(const edge & other) const{ return w<other.w; } 
};
edge E[10000000];

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
    inline ll find(ll u)
    {
        if (u==par[u]) return u;
        return par[u]=find(par[u]);
        }
    inline bool merge(ll u, ll v)
    {
        u=find(u);
        v=find(v);
        if (u==v) return false;
        if (size[u]<size[v]) swap(u, v);
        par[v]=u;
        size[u]+=size[v];   
        return true;
    }
};
DSU dsu(2005*2005);

void solve()
{
    setIO("fencedin");
    cin>>A>>B>>n>>m;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=m; i++) cin>>b[i];
    a[n+1]=A;
    b[m+1]=B;
    sort(a, a+n+1);
    sort(b, b+m+1);

    for (ll i=1; i<=m; i++)
        for (ll j=1; j<=n+1; j++)
            E[cnt++]={(i-1)*(n+1)+j, i*(n+1)+j, a[j]-a[j-1]};

    for (ll i=1; i<=m+1; i++)
        for (ll j=1; j<=n; j++)
            E[cnt++]={(i-1)*(n+1)+j, (i-1)*(n+1)+j+1, b[i]-b[i-1]};
    sort(E, E+cnt);
        
    long long ans=0;
    for (ll i=0; i<cnt; i++)
    {
        auto [u, v, w]=E[i];
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