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
vector<ll> adj[1000], back_adj[1000], topo;
set<ll> dp[1000];
bool vis[1000];

vector<ll> component;
ll ans = 0;
void dfs2(ll u)
{
    vis[u]=true;
    for (auto v: adj[u]) if (vis[v]==false) dfs2(v);
    topo.push_back(u);
}
 
void dfs3(ll u)
{
    vis[u]=true;
    component.push_back(u);
    for (auto v: back_adj[u]) if (vis[v]==false) dfs3(v);
}

void dfs(ll u)
{
    vis[u]=true;
    for (auto v: adj[u]) if (vis[v]==false)
    {
        dp[u].insert(v);
        dfs(v);
        for (auto i: dp[v]) dp[u].insert(i);
    }
}

void solve()
{
    ll n, m; cin>>n>>m;
    for (ll i=1; i<=m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        back_adj[v].push_back(u);
    }
    for (ll i=1; i<=n; i++) vis[i]=false;
    for (ll i=1; i<=n; i++) dfs2(i);
    reverse(topo.begin(), topo.end());

    for (ll i=1; i<=n; i++) vis[i]=false;
    for (ll i=1; i<=n; i++) if (vis[i]==false)
    {
        component.clear();
        dfs3(i);
        for (auto x: component) dp[i].insert(x);
    }

    for (ll i=1; i<=n; i++) vis[i]=false;
    for (ll i=1; i<=n; i++) if (vis[i]==false) dfs(i);
    ll ans=0;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) 
            if (dp[i].find(j)!=dp[i].end()) ++ans;
    
    for (ll i=1; i<=n; i++)
    {
        for (auto j: dp[i]) cout<<j<<" "; cout<<endl;
    }
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