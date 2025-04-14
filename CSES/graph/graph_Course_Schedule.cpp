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
ll n, m;
map<ll, vector<ll>> adj;
vector<ll> topo, degree;
vector<bool> visited;
 
bool kahn()
{
    queue<ll> q;  
    for (ll i=1; i<=n; i++) if (degree[i]==0) q.push(i);

    int cnt=0;
    while (!q.empty())
    {
        ll v=q.front(); q.pop();
        ++cnt;
        for (auto x: adj[v])
        {
            --degree[x];
            if (degree[x]==0) q.push(x);
        }
    }
    return n==cnt;
}

void dfs(ll u)
{
    visited[u]=true;  
    for (auto v: adj[u]) 
        if (visited[v]==false) dfs(v);
    topo.push_back(u);
}
 
void solve()
{
    cin>>n>>m;
    degree.resize(0); degree.resize(n+5, 0);
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        ++degree[v];
    }

    visited.resize(0); visited.resize(n+5, false);
    if (kahn()==false) cout<<"IMPOSSIBLE";
    else
    {
        for (ll i=1; i<=n; i++) if (visited[i]==false) dfs(i);
        reverse(topo.begin(), topo.end());
        for (auto it: topo) cout<<it<<" ";
    }
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