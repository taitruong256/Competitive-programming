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
ll n, sz[200005];
vector<ll> adj[200005];

void dfs(ll u, ll p)
{
    sz[u]=1;
    for (auto v: adj[u]) if (v!=p)
    {
        dfs(v, u);
        sz[u]+=sz[v];
    }
}

ll dfs2(ll u, ll p)
{
    pair<ll, ll> mx={0, u};
    for (auto v: adj[u]) if (v!=p) mx=max(mx, {sz[v], v});
    if (mx.first<=n/2) return u;
    return dfs2(mx.second, u);
}

void solve()
{
    cin>>n;
    for (ll i=1; i<n; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout<<dfs2(1, 0);
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