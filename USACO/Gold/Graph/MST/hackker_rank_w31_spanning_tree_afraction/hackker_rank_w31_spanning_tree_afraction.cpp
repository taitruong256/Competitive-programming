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
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
ll n, m, A, B;
ld l, r;
vector<ll> adj[100005];

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

struct edge { ll u, v, a, b; ld w;};
vector<edge> E;

bool comp(edge x, edge y)
{
    return x.w>y.w;
}

bool check(ld mid)
{
    for (auto &[u, v, a, b, w]: E) w=a-b*mid;
    sort(E.begin(), E.end(), comp);
    DSU dsu(n);
    A=0; B=0;
    for (auto [u, v, a, b, w]: E)
    {
        if (dsu.merge(u, v)==true)
        {
            A+=a;
            B+=b;
        }
    }
    return A>=B*mid;
}

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=m; i++)
    {
        ll u, v, a, b; cin>>u>>v>>a>>b;
        E.push_back({u, v, a, b, 0});
    }
    l=0; r=1e9;
    for (ll i=1; i<=70; i++)
    {
        ld mid=(l+r)/2;
        if (check(mid)==true) l=mid;
        else r=mid;
    }
    check(l);
    ll g=__gcd(A, B);
    A/=g;
    B/=g;
    cout<<A<<"/"<<B;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    // #ifndef ONLINE_JUDGE
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    // #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}