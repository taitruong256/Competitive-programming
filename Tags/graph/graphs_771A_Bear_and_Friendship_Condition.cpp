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
map<ll, vector<ll>> adj;
vector<bool> visited;

void dfs(ll u, ll &dinh, ll &canh)
{
    visited[u]=true;
    ++dinh;
    canh+=adj[u].size();
    for (auto v: adj[u]) if (visited[v]==false) dfs(v, dinh, canh);
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
    visited.resize(0);
    visited.resize(n+5, false);
    for (ll i=1; i<=n; i++) if (visited[i]==false)
    {
        ll dinh=0, canh=0;
        dfs(i, dinh, canh);      
        if (dinh*(dinh-1)!=canh) 
        {
            cout<<"NO";
            return;
        }
    }
    cout<<"YES";
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