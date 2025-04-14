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
const ll inf = 1e15;
ll n, m; 
vector<ll> adj[505];
ll f[505][505], rf[505][505];
vector<bool> visited;
vector<ll> parent;
vector<pair<ll, ll>> ans;
set<pair<ll, ll>> path;

void dfs(ll u)
{
    visited[u]=true;
    for (auto v: adj[u]) if (visited[v]==false && f[u][v]) dfs(v);
}

ll bfs(ll s, ll t)
{
    parent.resize(0); parent.resize(n+5, -1);
    parent[s]=-2;
    queue<pair<ll, ll>> q;
    q.push({s, inf});
 
    while (!q.empty())
    {
        ll u=q.front().first, flow=q.front().second; q.pop();
        for (auto v: adj[u]) if (parent[v]==-1 && f[u][v]>0)
        {
            parent[v]=u;
            ll next_flow=min(flow, f[u][v]);
            if (v==t) 
            {
                ans.push_back({u, v});
                return next_flow;
            }
            q.push({v, next_flow});
        }
    }
    return 0;
}
 
ll max_flow(ll s, ll t)
{
    ll new_flow=0, flow=0;
    while ((new_flow=bfs(s, t)))
    {   
        flow+=new_flow;
        ll v=t;
        while (v!=s)
        {
            ll u=parent[v];
            f[u][v]-=new_flow;    //  cout<<u<<" "<<v<<endl;
            f[v][u]+=new_flow;    //path.insert({u, v});
            v=u;
        }
    }   
    return flow;
}
 
void solve()
{
    cin>>n>>m;
    for (ll i=0; i<=501; i++)   
        for (ll j=0; j<=501; j++) f[i][j]=rf[i][j]=0;
    for (ll i=0; i<m; i++)
    {
        ll u, v, w; cin>>u>>v;
        w=1;
        f[u][v]+=w;
        f[v][u]+=w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<max_flow(1, n)<<endl;
    visited.resize(0); visited.resize(n+5, false);
    dfs(1);
    // for (ll i=1; i<=n; i++) cout<<visited[i]<<" "; cout<<endl;

    for (ll i=1; i<=n; i++) if (visited[i]==true)
        for (ll j: adj[i]) if (visited[j]==false)  cout<<i<<" "<<j<<endl;
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