#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define orderset tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
ll n, m, num[10005], low[10005], time_dfs, joint[10005], bridge;
vector<ll> adj[10005];

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
    for (ll i=1; i<=n; i++) if (num[i]==0) dfs(i, i);
    ll cntjoint=0;
    for (ll i=1; i<=n; i++) cntjoint+=joint[i];
    cout<<cntjoint<<" "<<bridge;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    solve();
    return 0;
}
