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
vector<ll> adj[100005], back_adj[100005];
vector<bool> visited, visited2;

void dfs(ll u)
{
    visited[u]=true;
    for (auto v: adj[u]) if (visited[v]==false) dfs(v);
}

void dfs2(ll u)
{
    visited2[u]=true;
    for (auto v: back_adj[u]) if (visited2[v]==false) dfs2(v);
}

void solve()
{
    cin>>n>>m;
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        back_adj[v].push_back(u);
    }

    visited.resize(0); visited.resize(n+5, false);
    dfs(1);
    visited2.resize(0); visited2.resize(n+5, false);
    dfs2(1);

    for (ll i=1; i<=n; i++) if (visited[i]==false || visited2[i]==false)
    {
        if (visited[i]==false)
        {
            cout<<"NO\n";
            cout<<1<<" "<<i;
            return;
        }
        else 
        {
            cout<<"NO\n";
            cout<<i<<" "<<1;
            return;
        }
    }
    cout<<"YES";
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