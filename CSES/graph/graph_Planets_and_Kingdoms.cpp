/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const ll mod = 1e9+7;
const ll inf = 1e9;
const ll maxn = 5e5+5;
ll n, m, k=0;
vector<ll> adj[100005], back_adj[100005], topo;
vector<ll> visited;

void dfs(ll u)
{
    visited[u]=1;
    for (auto v: adj[u]) if (visited[v]==0) dfs(v);
    topo.push_back(u);
}

void dfs2(ll u)
{
    visited[u]=k;
    for (auto v: back_adj[u]) if (visited[v]==0) dfs2(v);
}

void solve()
{
    cin>>n>>m;
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        back_adj[v].push_back(u);
    }
    visited.resize(0); visited.resize(n+5, 0);
    for (ll i=1; i<=n; i++) if (visited[i]==0) dfs(i);
    reverse(topo.begin(), topo.end());

    // for (auto it: topo) cout<<it<<" "; cout<<endl;
    visited.resize(0); visited.resize(n+5, 0);
    for (ll i=0; i<n; i++) if (visited[topo[i]]==0) ++k, dfs2(topo[i]);

    cout<<k<<endl;
    for (ll i=1; i<=n; i++) cout<<visited[i]<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}