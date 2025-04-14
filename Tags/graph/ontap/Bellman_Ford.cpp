#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, d[2505];
vector<ll> adj[2505], adj2[2505];
bool vis[2505], vis2[2505], negative_cycle=false;

struct edge
{
    ll u, v, w;
    edge(){}
    edge(ll _u, ll _v, ll _w){u=_u; v=_v; w=_w;}
};
vector<edge> e;

void dfs(ll u)
{
    vis[u]=true;
    for (auto v: adj[u]) if (vis[v]==false) dfs(v);
}

void dfs2(ll u)
{
    vis2[u]=true;
    for (auto v: adj2[u]) if (vis2[v]==false) dfs2(v);
}

void solve()
{
    cin>>n>>m;
    for (ll i=0; i<m; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        e.push_back(edge(u, v, -w));
        adj[u].push_back(v);
        adj2[v].push_back(u);
    }

    for (ll i=1; i<=n; i++) d[i]=1e18;
    d[1]=0;
    dfs(1);
    dfs2(n);
    for (ll i=1; i<=n; i++)
    {
        for (auto j: e)
        {
            ll u=j.u, v=j.v, w=j.w;
            if(d[u]<1e18 && d[u]+w<d[v])
            {
                if (i==n && vis[u]==true && vis2[v]==true) negative_cycle=true;
                d[v]=d[u]+w;
            }
        }
    }

    if(negative_cycle==true) cout<<-1;
    else cout<<-d[n];
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
