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
ll n, m;
map<ll, vector<ll>> adj, trans_adj;
vector<bool> visited;
vector<ll> thutu;

void topo(ll u)
{
    visited[u]=true;
    for (auto v: adj[u]) if (visited[v]==false) topo(v);
    thutu.push_back(u);
}

void dfs(ll u)
{
    visited[u]=true;
    for (auto v: trans_adj[u]) if (visited[v]==false) dfs(v);
}

void solve()
{
    cin>>n>>m;
    for (auto i: adj) i.second.clear();
    for (auto i: trans_adj) i.second.clear();
    adj.clear(); trans_adj.clear();
    visited.resize(0); visited.resize(n+5, false);
    thutu.resize(0);
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        trans_adj[v].push_back(u);
    }
    for (ll i=1; i<=n; i++) if (visited[i]==false) topo(i);
    reverse(thutu.begin(), thutu.end());
    visited.resize(0); visited.resize(n+5, false);
    ll ans=0;
    for (auto i: thutu) if (visited[i]==false) dfs(i), ++ans;
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