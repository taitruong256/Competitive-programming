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
vector<ll> parent, path;
bool ok=false;

void dfs(ll u)
{
    visited[u]=true;
    for (auto v: adj[u])
    {
        if (visited[v]==false) 
        {
            dfs(v);
            parent[v]=u;
        }
        else
        {
            ok=true;
            ll x=v;
            path.clear();
            while (x!=0)
            {
                path.push_back(x);
                x=parent[x];
            }
            reverse(path.begin(), path.end());
            // path.push_back(path.front());
        }
    }
}

void solve()
{
    cin>>n>>m;
    visited.resize(0); visited.resize(n+5, false);
    parent.resize(0); parent.resize(n+5, 0);
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ok=true;
    for (ll i=1; i<=n; i++) if (visited[i]==false) dfs(i);
    if (ok) for (auto it: path) cout<<it<<" ";
    else cout<<"IMPOSSIBLE";
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