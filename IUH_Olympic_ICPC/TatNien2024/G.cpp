#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define orderset tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
ll n, m, num[300005], low[300005], time_dfs, joint[300005], bridge, sz[300005], vis[300005], ans=0;
vector<ll> adj[300005];

void dfs_size(ll u)
{
    vis[u]=true;
    sz[u]=1;
    for (ll v: adj[u]) if (vis[v]==false) 
    {
        dfs_size(v);
        sz[u]+=sz[v];
    }
}

void dfs(ll u, ll par)
{
    num[u]=low[u]=++time_dfs;
    ll child=0;
    for (auto v: adj[u])
    {
        if (v==par) continue;
        if (num[v]==0)
        {
            dfs(v, u);
            ++child;
            low[u]=min(low[u], low[v]);
            if (low[v]==num[v]) ++bridge;
            if (low[v]>=num[u] && u!=par) joint[u]=1;
        }
        else low[u]=min(low[u], num[v]);
    }
    if (u==par && child>1) joint[u]=1;
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
    for (ll i=1; i<=n; i++) if (vis[i]==0) dfs_size(i);
    for (ll i=1; i<=n; i++) if (num[i]==0) dfs(i, i);
    for (ll i=2; i<=n; i++) if (low[i]==num[i]) ans+=sz[i]*(n-sz[i]);
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    solve();
    return 0;
}
