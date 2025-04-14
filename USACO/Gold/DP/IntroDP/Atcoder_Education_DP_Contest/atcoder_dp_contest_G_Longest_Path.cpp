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
const ll maxn = 2e5+5;
ll n, m, dp[100005];
vector<ll> adj[maxn];

ll dfs(ll u)
{
    if (dp[u]!=-1) return dp[u];
    ll res=0;
    for (auto v: adj[u]) res=max(res, dfs(v)+1);
    return dp[u]=res;
}
 
void solve()
{
    cin>>n>>m;
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
    }
    for (ll i=1; i<=n; i++) dp[i]=-1;
    ll ans=0;
    for (ll i=1; i<=n; i++) ans=max(ans, dfs(i));
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