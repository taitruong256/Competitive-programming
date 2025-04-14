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
ll n;
map<ll, vector<ll>> adj;
ll dp[200005];
bool visited[200005];

void dfs(ll u)
{
    visited[u]=true;
    dp[u]=0;
    for (auto v: adj[u]) if (visited[v]==false)
    {
        dfs(v);
        dp[u]+=dp[v];
        ++dp[u];
    }
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) visited[i]=false;
    for (ll i=2; i<=n; i++)
    {
        ll x; cin>>x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    dfs(1);
    for (ll i=1; i<=n; i++) cout<<dp[i]<<" ";
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