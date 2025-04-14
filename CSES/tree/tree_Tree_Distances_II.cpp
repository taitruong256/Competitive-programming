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
ll n; 
map<ll, vector<ll>> adj;
vector<ll> sz, down, up;

void dfs1(ll u, ll p)
{
    sz[u]=1;
    for (auto v: adj[u]) if (v!=p)
    {
        dfs1(v, u);
        sz[u]+=sz[v];
        down[u]+=down[v]+sz[v];
    }
}

void dfs2(ll u, ll p)
{
    if (p!=0) up[u]=up[p]+down[p]+n-2*sz[u]-down[u];
    for (auto v: adj[u]) if (v!=p) dfs2(v, u);
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    sz.resize(0); sz.resize(n+5, 0);
    down.resize(0); down.resize(n+5, 0);
    up.resize(0); up.resize(n+5, 0);
    dfs1(1, 0);
    dfs2(1, 0);
    // for (ll i=1; i<=n; i++) cout<<sz[i]<<" "; cout<<endl;
    // for (ll i=1; i<=n; i++) cout<<down[i]<<" "; cout<<endl;
    // for (ll i=1; i<=n; i++) cout<<up[i]<<" "; cout<<endl;
    for (ll i=1; i<=n; i++) cout<<down[i]+up[i]<<" ";
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