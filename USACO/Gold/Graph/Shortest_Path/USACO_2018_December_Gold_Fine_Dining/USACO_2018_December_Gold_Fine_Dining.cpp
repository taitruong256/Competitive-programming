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
ll n, m, k, id[50005], y[50005];
vector<pair<ll, ll>> adj[50005];
vector<ll> d1, d2;

vector<ll> dijktra( ll s)
{
    vector<ll> d(n+5, 1e18);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    d[s]=0;
    pq.push({0, s});
    while (!pq.empty())
    {
        auto [W, u]=pq.top(); pq.pop();
        if (W>d[u]) continue;
        for (auto [v, w]: adj[u]) 
            if (d[u]+w<d[v])
            {
                d[v]=d[u]+w;
                pq.push({d[v], v});
            }
    }
    return d;
}

void solve()
{
    setIO("dining");
    cin>>n>>m>>k;
    for (ll i=1; i<=m; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (ll i=1; i<=k; i++) cin>>id[i]>>y[i];
    d1=dijktra(n);
    for (ll i=1; i<=k; i++)
        adj[n+1].push_back({id[i], d1[id[i]]-y[i]});
    d2=dijktra(n+1);
    for (ll i=1; i<=n-1; i++) cout<<(d1[i]>=d2[i])<<endl;
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