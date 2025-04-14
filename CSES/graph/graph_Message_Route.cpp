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
vector<bool> visited;
vector<ll> path, parent;

void bfs(ll u)
{
    queue<ll> q;
    q.push(u);
    visited[u]=true;
    parent[1]=0;
    while (!q.empty())
    {
        ll x=q.front(); q.pop(); 
        for (auto v: adj[x]) if (visited[v]==false)
        {
            visited[v]=true;
            q.push(v);
            parent[v]=x;
        }
    }
}

void solve()
{
    cin>>n>>m;
    visited.resize(0); visited.resize(n+5, false);
    parent.resize(0); parent.resize(n+5);
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    if (visited[n]==true)
    {
        vector<ll> path;
        ll u=n;
        while (u!=0)
        {
            path.push_back(u);
            u=parent[u];
        }
        reverse(path.begin(), path.end());
        cout<<path.size()<<endl;
        for (auto it: path) cout<<it<<" ";
    }
    else
    {
        cout<<"IMPOSSIBLE";
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