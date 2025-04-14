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
vector<ll> adj[200005];
set<ll> st[200005];
ll n, ans[200005], color[200005];

void dfs(ll u, ll p)
{
    st[u].insert(color[u]);
    for (auto v: adj[u]) if (v!=p)
    {
        dfs(v, u);
        if (st[u].size()<st[v].size()) swap(st[u], st[v]);
        for (auto x: st[v]) st[u].insert(x);
    }
    ans[u]=st[u].size();
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>color[i];
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for (ll i=1; i<=n; i++) cout<<ans[i]<<" "; cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef LOCAL
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}