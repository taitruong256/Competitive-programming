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
const ll mod = 1e9+7;
const ll inf = 1e18;
ll n, m, d[100005], trace[100005];
vector<pair<ll, ll>> adj[100005];
bool vis[100005];

void dijkstra(ll s)
{
    for (ll i=1; i<=n; i++) d[i]=inf;
    d[s]=0;

    for (ll i=1; i<=n; i++)
    {
        ll u=-1, mn=inf;
        for (ll idx=1; idx<=n; idx++) if (vis[idx]==false && d[idx]<mn) 
        {
            u=idx;
            mn=d[idx];
        }

        vis[u]=true;
        for (auto [v, w]: adj[u])
        {
            if (d[u]+w<d[v])
            {
                d[v]=d[u]+w;
                trace[v]=u;
            }
        } 
    }
}

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=m; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
    }

    dijkstra(1);
    for (ll i=1; i<=n; i++) cout<<d[i]<<" ";
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