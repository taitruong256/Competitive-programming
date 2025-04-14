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
vector<ll> adj[2505];
ll n, m, ans=1e9, d[2505], par[2505];

void bfs(ll s)
{
    queue<ll> q;
    q.push(s);
    d[s]=0;
    while (!q.empty())
    {
        ll u=q.front(); q.pop();
        for (auto v: adj[u]) if (v!=par[u])
        {
            if (d[v]==-1)
            {
                q.push(v);
                d[v]=d[u]+1;
                par[v]=u;
            }
            else 
                ans=min(ans, d[u]+d[v]+1);
        }
    }
}

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (ll i=1; i<=n; i++)
    {
        for (ll j=1; j<=n; j++) d[j]=-1;
        for (ll j=1; j<=n; j++) par[j]=0;
        bfs(i);
    }
    if (ans==1e9) ans=-1;
    cout<<ans;
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