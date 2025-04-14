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
ll n, m, c;
vector<pair<ll, ll>> adj[100005];
bool vis[100005];
vector<ll> topo;
ll timer[100005];

void topo_sort(ll u)
{
    vis[u]=true;
    for (auto [v, w]: adj[u]) if (vis[v]==false) topo_sort(v);
    topo.push_back(u);
}

void solve()
{
    setIO("timeline");
    cin>>n>>m>>c;
    for (ll i=1; i<=n; i++) cin>>timer[i];
    for (ll i=0; i<c; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
    }
    for (ll i=1; i<=n; i++) if (vis[i]==false) topo_sort(i);
    reverse(topo.begin(), topo.end());
    for (auto u: topo)
    {
        for (auto [v, w]: adj[u])
        timer[v]=max(timer[v], timer[u]+w);
    }
    for (ll i=1; i<=n; i++) cout<<timer[i]<<endl; 
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