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
ll n, q, ans[100005];
struct edge
{
    ll u, v, w;
};
deque<edge> E;
struct query
{
    ll k, v, id;
};
deque<query> Q;

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
    ll getsize(ll u)
    {
        u=find(u);
        return size[u];
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

bool comp1(edge a, edge b)
{
    return a.w>b.w;
}

bool comp2(query a, query b)
{
    return a.k>b.k;
}

void solve()
{
    setIO("mootube");
    cin>>n>>q;
    for (ll i=0; i<n-1; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        E.push_back({u, v, w});
    }
    for (ll i=0; i<q; i++)
    {
        ll k, v; cin>>k>>v;
        Q.push_back({k, v, i});
    }
    sort(E.begin(), E.end(), comp1);
    sort(Q.begin(), Q.end(), comp2);
    DSU dsu(n+5);
    for (auto [k, v, id]: Q)
    {
        while (!E.empty() && E.front().w>=k) 
        {
            auto [x, y, w]=E.front(); E.pop_front();
            dsu.merge(x, y);
        }
        ans[id]=dsu.getsize(v);
    }
    for (ll i=0; i<q; i++) cout<<ans[i]-1<<endl;
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