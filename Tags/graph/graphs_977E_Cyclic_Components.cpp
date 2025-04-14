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
map<ll, vector<ll>> adj;
vector<bool> visited;
vector<ll> components, degree;

void dfs(ll u)
{
    visited[u]=true;
    components.push_back(u);
    for (auto v: adj[u]) if (visited[v]==false) dfs(v);
}

void solve()
{
    ll n, m; cin>>n>>m;
    degree.resize(0); degree.resize(n+5, 0);
    visited.resize(0); visited.resize(n+5, false);
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++degree[u];
        ++degree[v];
    }

    ll ans=0;
    for (ll i=1; i<=n; i++) if (visited[i]==false)
    {
        components.clear();
        dfs(i);
        bool check=true;
        for (auto v: components) if (degree[v]!=2) check=false;
        if (check==true) ++ans;
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}