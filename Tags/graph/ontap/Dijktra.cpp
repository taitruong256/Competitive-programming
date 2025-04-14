#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
ll n, m, d[100005], truoc[100005];
vector<pair<ll, ll>> adj[100005];

void truyvet(ll u)
{
    if (u==0) return;
    truyvet(truoc[u]);
    cout<<u<<" ";
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

    for (ll i=1; i<=n; i++) d[i]=1e18;
    d[1]=0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto [w, u]=pq.top(); pq.pop();
        for (auto [v, wi]: adj[u])
        {
            if (w>d[v]) continue;
            if (d[u]+wi<d[v])
            {
                truoc[v]=u;
                d[v]=d[u]+wi;
                pq.push({d[v], v});
            }
        }
    }
    if (d[n]==1e18) cout<<-1;
    else truyvet(n);
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

