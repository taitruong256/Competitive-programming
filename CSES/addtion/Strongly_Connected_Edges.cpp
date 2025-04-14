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
ll n, m, num[100005], low[100005], timeDfs;
vector<pair<ll, ll>> adj[100005];
bool vis[100005], bridge, used[200005];
vector<pair<ll, ll>> ans;

void dfs(ll u, ll p)
{
    vis[u]=true;
    num[u]=low[u]=++timeDfs;
    for (auto [v, i]: adj[u])
    {
        if (v==p) continue;
        if (used[i]==true) continue;
        used[i]=true;
        ans.push_back({u, v});
        if (num[v]==0) 
        {
            dfs(v, u);
            low[u]=min(low[u], low[v]);
            if (low[v]==num[v]) bridge=true;
        }
        else low[u]=min(low[u], num[v]);
    }
}

void solve()
{
    cin>>n>>m;
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    dfs(1, 0);
    if (bridge==true)
    {
        cout<<"IMPOSSIBLE";
        return;
    }
    for (ll i=1; i<=n; i++) if (vis[i]==false)
    {
        cout<<"IMPOSSIBLE";
        return;
    }
    for (auto [u, v]: ans) cout<<u<<" "<<v<<endl;
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