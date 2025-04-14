#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define orderset tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
ll n, m;
vector<pair<ll, ll>> adj[100005];
ll d[100005];
bool vis[100005];

void dfs(ll u)
{
    vis[u]=true;
    for (auto v: adj[u]) if (vis[v.first]==false) dfs(v.first);
}

void debugg(priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq)
{
    while (!pq.empty())
    {
        auto [w, u]=pq.top(); pq.pop();
        cout<<w<<" "<<u<<endl;
    }
}

void solve()
{
    cin>>n>>m;
    for (ll i=0; i<m; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(1);
    for (ll i=1; i<=n; i++) if (vis[i]==false)
    {
        cout<<"IMPOSSIBLE";
        return;
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (ll i=1; i<=n; i++) d[i]=1e18;
    for (ll i=1; i<=n; i++) vis[i]=false;
    d[1]=0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto [w, u]=pq.top(); pq.pop();
        vis[u]=true;
        if (w>d[u]) continue;
        for (auto [v, wi]: adj[u]) if (vis[v]==false && wi<d[v])
        {
            d[v]=wi;
            pq.push({d[v], v});
        }
    }
    ll ans=0;
    for (ll i=1; i<=n; i++) ans+=d[i];
    cout<<ans;
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
