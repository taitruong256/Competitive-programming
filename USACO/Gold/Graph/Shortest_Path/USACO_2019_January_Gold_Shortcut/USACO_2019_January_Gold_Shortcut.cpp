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
ll n, m, t, cnt[10005], occ[10005], dist[10005], par[10005];
vector<pair<ll, ll>> adj[10005];

void solve()
{
    setIO("shortcut");
    cin>>n>>m>>t;
    for (ll i=1; i<=n; i++) cin>>cnt[i];
    for (ll i=1; i<=m; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (ll i=1; i<=n; i++) dist[i]=par[i]=1e18;
    dist[1]=0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto [W, u]=pq.top(); pq.pop();
        if (W>dist[u]) continue;
        for (auto [v, w]: adj[u])
        {
            if (dist[u]+w<dist[v])
            {
                dist[v]=dist[u]+w;
                par[v]=u;
                pq.push({dist[v], v});
            }
            else if (dist[u]+w==dist[v] && u<=par[v])
            {
                par[v]=u;
                pq.push({dist[v], v});
            }
        }
    }
    for (ll i=1; i<=n; i++)
    {
        ll x=i;
        while (x!=1e18)
        {
            occ[x]+=cnt[i];
            x=par[x];
        }
    }
    ll ans=0;
    for (ll i=2; i<=n; i++) ans=max(ans, occ[i]*(dist[i]-t));
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