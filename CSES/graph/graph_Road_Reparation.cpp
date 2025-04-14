#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
 
struct edge
{
    ll u, v, w;
    edge(){}
    edge(ll _u, ll _v, ll _w) {u=_u; v=_v; w=_w;}
};
 
ll n, m, ans;
edge e[200005];
bool vis[100005];
vector<ll> adj[100005];
 
struct DSU
{
    ll n;
    vector<ll> par, sz;
    DSU();
    DSU(ll _n)
    {
        n=_n;
        par.resize(n+5);
        sz.resize(n+5);
        for (ll i=0; i<=n; i++) par[i]=i;
        for (ll i=0; i<=n; i++) sz[i]=1;
    }
 
    ll find(ll u)
    {
        if (u==par[u]) return u;
        return par[u]=find(par[u]);
    }
 
    bool merge(ll u, ll v)
    {
        u=find(u);
        v=find(v);
        if (u==v) return false;
        if (sz[u]<sz[v]) swap(u, v);
        par[v]=u;
        sz[u]+=sz[v];
        return true;
    }
};
 
void dfs(ll u)
{
    vis[u]=true;
    for (auto v: adj[u]) if (vis[v]==false) dfs(v);
}
 
bool comp(edge a, edge b)
{
    return a.w<b.w;
}
 
void kruskal()
{
    sort(e+1, e+m+1, comp);
    DSU dsu(n);
    for (ll i=1; i<=m; i++)
        if (dsu.merge(e[i].u, e[i].v)==true) ans+=e[i].w;
    cout<<ans;
}
 
void solve()
{
    cin>>n>>m; 
    for (ll i=1; i<=m; i++)
    {
        cin>>e[i].u>>e[i].v>>e[i].w;
        adj[e[i].u].push_back(e[i].v);
        adj[e[i].v].push_back(e[i].u);
    }
    dfs(0);
    for (ll i=0; i<=n-1; i++) if (vis[i]==false)
    {
        cout<<"IMPOSSIBLE";
        return;
    }
    kruskal();
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
