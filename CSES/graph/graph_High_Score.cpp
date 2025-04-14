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
const ll inf = 1e18;

struct edge{ll u, v, w;};
vector<edge> E;
ll n, m, d[2505];
vector<ll> adj[2505], adj_rev[2505];
bool vis_1[2505], vis_n[2505];
bool negative_cycle=false;

void dfs_1(ll u)
{
    vis_1[u]=true;
    for (auto v: adj[u]) if (vis_1[v]==false) dfs_1(v);
}

void dfs_n(ll u)
{
    vis_n[u]=true;
    for (auto v: adj_rev[u]) if (vis_n[v]==false) dfs_n(v);
}

void Bellman_Ford(ll s)
{
    d[s]=0;
    for (ll i=1; i<=n; i++)
        for (auto e: E) if (d[e.u]<inf && d[e.u]+e.w<d[e.v])
        {
            d[e.v]=d[e.u]+e.w;
            if (i==n && vis_1[e.u]==true && vis_n[e.v]==true) negative_cycle=true;
            // neu chu trinh am tren duong di tu 1 den n
        }
}

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=n; i++) d[i]=inf;
    for (ll i=0; i<m; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        E.push_back({u, v, -w});       //de trong so =-w de tim max
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }

    dfs_1(1);   //danh dau cac dinh u di duoc tu 1 den u
    dfs_n(n);   //danh dau cac dinh u di duoc tu u den n
    Bellman_Ford(1);
    if (negative_cycle==true) cout<<-1;
    else cout<<-d[n];
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