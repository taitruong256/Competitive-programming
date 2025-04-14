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
vector<ll> adj[100005];
ll n, root, mn, mx;
bool vis[100005];

void dfs(ll u, ll d)
{
    vis[u]=true;
    if (adj[u].size()==1)
    {
        if (d%2!=0) mn=3;
    }
    for (auto v: adj[u]) if (vis[v]==false) dfs(v, d+1);
}

void dfs2(ll u)
{
    vis[u]=true;
    if (adj[u].size()==1) --mx;
    else for (auto v: adj[u]) if (adj[v].size()==1) 
    {
        ++mx;
        break;
    }
    for (auto v: adj[u]) if (vis[v]==false) dfs2(v);
}

void solve()
{
    cin>>n;
    for (ll i=0; i<n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (ll i=1; i<=n; i++) if (adj[i].size()==1) root=i;
    mn=1;
    dfs(root, 0);
    mx=n-1;
    for (ll i=1; i<=n; i++) vis[i]=false;
    dfs2(root);
    cout<<mn<<" "<<mx;
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