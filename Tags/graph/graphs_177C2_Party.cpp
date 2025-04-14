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
ll n, k, m, tplt=0;
ll vis[2005], sz[2005];
bool check[2005];
map<ll, vector<ll>> adj;

void dfs(ll u)
{                
    ++sz[tplt];
    vis[u]=tplt;
    for (auto v: adj[u]) if (vis[v]==0) dfs(v);
}

void solve()
{
    cin>>n>>m;
    adj.clear();
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(vis, 0, sizeof(vis));
    memset(check, true, sizeof(check));
    memset(sz, 0, sizeof(sz));
    for (ll i=1; i<=n; i++) if (vis[i]==0)
    {
        ++tplt;
        dfs(i);    cout<<i<<" "<<tplt<<" "<<sz[tplt]<<endl;
    }
    cin>>k;
    for (ll i=0; i<k; i++)
    {
        ll u, v; cin>>u>>v;
        if (vis[u]==vis[v]) check[vis[u]]=false;
    }
    ll ans=0;
    for (ll i=1; i<=tplt; i++) if (check[i]==true) ans=max(ans, sz[i]);
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