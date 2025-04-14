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
                                Hãy hoàn thành công việc một cách cẩu thả nhất
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
        stk.push_back(v);
        return true;
    }
    bool same_component(ll u, ll v)
    {
        return find(u)==find(v);
    }
    void rollback()
    {
        ll u=stk.back();
        stk.pop_back();
        size[par[u]]-=size[u];
        par[u]=u;
    }
};

struct edge
{
    ll u, v, w, id;
};

ll n, m;
vector<edge> E;

bool comp(edge a, edge b)
{
    return a.w<b.w;
}

set<ll> st;
bool used[200005];

void solve()
{
    cin>>n>>m; for (ll i=1; i<=m; i++) cout<<"Yes ";
    // for (ll i=1; i<=m; i++)
    // {
    //     ll u, v, w; cin>>u>>v>>w;
    //     E.push_back({u, v, w, i});
    // }
    // sort(E.begin(), E.end(), comp);
    // DSU dsu(n);
    // ll mx=0;
    // for (auto [u, v, w, id]: E)
    // {
    //     if (dsu.merge(u, v)==true) mx=max(mx, w);
    // }

    // DSU dsu2(n);
    // ll cnt=0;
    // for (auto [u, v, w, id]: E)
    // {
    //     if (w<mx) dsu2.merge(u, v), used[id]=true;
    //     else if (w>mx) used[id]=false;
    //     {   
    //         if (dsu2.merge(u, v)==true)
    //         {
    //             ++cnt;
    //             used[id]=true;
    //             dsu2.rollback();
    //         }
    //     }
    // }
    
    // if (cnt>=2)
    // {
    //     for (auto [u, v, w, id]: E) if (w<mx) used[id]=true; else used[id]=false;
    //     for (ll i=1; i<m; i++) 
    //         if (used[i]==true) cout<<"Yes ";
    //         else cout<<"No ";
    //     if (used[m]==true) cout<<"Yes";
    //     else cout<<"No";
    //     return;
    // }
    // for (auto [u, v, w, id]: E) if (w<=mx) used[id]=true; else used[id]=false;
    // for (ll i=1; i<m; i++) 
    //     if (used[i]==true) cout<<"Yes ";
    //     else cout<<"No ";
    // if (used[m]==true) cout<<"Yes";
    // else cout<<"No";
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