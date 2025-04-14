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
ll n, m, fartherst, ans;
map<ll, vector<ll>> adj;
vector<bool> visited;
vector<ll> depth;

void bfs(ll u)
{
    queue<ll> q;
    q.push(u);
    visited[u]=true;
    depth[u]=0;
    while (!q.empty())
    {
        ll v=q.front(); q.pop();
        fartherst=v;
        for (auto x: adj[v]) if (visited[x]==false)
        {
            visited[x]=true;
            q.push(x);
            depth[x]=depth[v]+1;
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
    depth.resize(0); depth.resize(n+5, 0);
    bfs(1);
    ans=depth[fartherst];
    visited.resize(0); visited.resize(n+5, false);
    depth.resize(0); depth.resize(n+5, 0);
    bfs(fartherst);
    ans=max(ans, depth[fartherst]);
    cout<<ans;
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