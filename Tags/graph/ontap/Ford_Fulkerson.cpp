#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define orderset tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
ll n, m, c[505][505], par[505];
vector<ll> adj[505];

ll bfs()
{
    for (ll i=1; i<=n; i++) par[i]=0;
    queue<pair<ll, ll>> q;
    q.push({1, 1e18});
    par[1]=-1;
    while (!q.empty())
    {
        auto [u, w]=q.front(); q.pop();
        if (u==n) return w;
        for (auto v: adj[u]) if (par[v]==0 && c[u][v]>0)
        {
            par[v]=u;
            q.push({v, min(w, c[u][v])});
        }
    }
    return 0;
}

void solve()
{
    cin>>n>>m;
    for (ll i=0; i<m; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        c[u][v]+=w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll ans=0, cnt=0;
    while (true)
    {
        ll x=bfs();
        if (x==0) break;
        ans+=x;
        ll v=n;
        while (v!=1)
        {
            ll u=par[v];
            c[u][v]-=x;
            c[v][u]+=x;
            v=u;
        }
    }
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
