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
vector<ll> adj[200005];
vector<bool> visited;
vector<ll> path;

void dfs(ll u)
{
    queue<ll> q;
    q.push(u);
    visited[u]=true;
    while (!q.empty())
    {
        ll u=q.front(); q.pop();
        for (auto v: adj[u]) if (visited[v]==false)
        {
            q.push(v);
            visited[v]=true;
        }
    }
}

void solve()
{
    cin>>n>>m;
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited.resize(0); visited.resize(n+5, false);
    for (ll i=1; i<=n; i++) if (visited[i]==false)
    {
        path.push_back(i);
        dfs(i);
    }
    cout<<path.size()-1<<endl;
    for (ll i=0; i<path.size()-1; i++) cout<<path[i]<<" "<<path[i+1]<<endl;
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