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

struct edge
{
    ll v, cost, flow;
};
ll n, m;
vector<edge> adj[1005];
vector<ll> flows;

ll dijktra(ll min_flow)
{
    vector<ll> d(n+5, 1e18);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    d[1]=0;
    pq.push({0, 1});      
    while (!pq.empty())
    {
        auto [w, u]=pq.top(); pq.pop();    
        if (w>d[u]) continue;
        for (auto [v, cost, flow]: adj[u])
        {
            if (flow<min_flow) continue;
            if (d[u]+cost<d[v])
            {
                d[v]=d[u]+cost;
                pq.push({d[v], v});
            }
        }
    }
    double ratio=double(min_flow)/double(d[n])*1000000;
    return ratio;
}

void solve()
{
    setIO("pump");
    cin>>n>>m;
    for (ll i=0; i<m; i++)
    {
        ll u, v, c, f; cin>>u>>v>>c>>f;
        adj[u].push_back({v, c, f});
        adj[v].push_back({u, c, f});
        flows.push_back(f);
    }
    ll ans=0;
    for (auto f: flows) 
        ans=max(ans, dijktra(f));
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