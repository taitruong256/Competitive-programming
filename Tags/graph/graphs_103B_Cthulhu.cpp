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
ll n, m, cnt=0;
map<ll, vector<ll>> adj;
vector<bool> visited;

void dfs(ll u)
{
    ++cnt;
    visited[u]=true;
    for (auto v: adj[u]) if (visited[v]==false) dfs(v);
}

void solve()
{
    cin>>n>>m;
    if (n!=m)
    {
        cout<<"NO";
        return;
    }
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    visited.resize(0);
    visited.resize(n+5, false);
    dfs(1);
    if (cnt==n)
    {
        cout<<"FHTAGN!";
        return;
    }
    cout<<"NO";
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