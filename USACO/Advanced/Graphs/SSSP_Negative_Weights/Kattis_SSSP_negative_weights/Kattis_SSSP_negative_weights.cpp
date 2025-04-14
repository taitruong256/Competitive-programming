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
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e18;

struct Bellman_Ford
{
    struct Edge { ll u, v, w; };
    ll n, m, s, inf=1e18;
    vector<ll> dist, par, negative_cycle;
    vector<Edge> E;
    Bellman_Ford(){}
    Bellman_Ford(ll _n, ll _m, ll _s)
    {
        n=_n;
        m=_m;
        s=_s;
        dist.resize(n+5, inf);
        par.resize(n+5, -1);
    }

    void add_edge(ll u, ll v, ll w)
    {
        E.push_back({u, v, w});
    }

    void shortest_path()
    {
        dist[s]=0;
        for (ll i=1; i<=n-1; i++)
        {
            for (auto [u, v, w]: E) 
                if (dist[u]<inf && dist[u]+w<dist[v])
                {
                    dist[v]=dist[u]+w;
                    par[v]=u;
                }
        }
        for (ll i=1; i<=n; i++)
            for (auto [u, v, w]: E) if (dist[u]<inf && dist[u]+w<dist[v])
                dist[v]=-inf;
    }
};

bool fi=false;

void solve()
{
    ll n, m, q, s; cin>>n>>m>>q>>s;
    if (n==0) 
    {
        fi=true;
        return;
    }
    Bellman_Ford bf(n, m, s);
    while (m--)
    {
        ll u, v, w; cin>>u>>v>>w;
        bf.add_edge(u, v, w);
    }
    bf.shortest_path();
    while (q--)
    {
        ll x; cin>>x;
        ll ans=bf.dist[x];
        if (ans==-inf) cout<<"-Infinity\n";
        else if (ans==inf) cout<<"Impossible\n";
        else cout<<ans<<endl;
    }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    while (fi==false) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}