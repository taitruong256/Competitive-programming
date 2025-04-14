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
ll n, m, k=0;
vector<ll> adj[100005], back_adj[100005], scc[100005];
vector<bool> visited;
vector<ll> component, sum, coins, topo, c, dp;
ll ans = 0;
void dfs(ll u)
{
    visited[u]=true;
    for (auto v: adj[u]) if (visited[v]==false) dfs(v);
    topo.push_back(u);
}
 
void dfs2(ll u)
{
    visited[u]=true;
    component.push_back(u);
    for (auto v: back_adj[u]) if (visited[v]==false) dfs2(v);
}
 
void dfs3(ll u)
{
    visited[u]=true;
    dp[u]=sum[u];
    for (auto v: scc[u]) 
    {
        if (visited[v]==false) dfs3(v);
        dp[u]=max(dp[u], dp[v]+sum[u]);
    }
}
vector<int> loc(700), tongl(700);
void dfsloc(int x) {
    if (visited[x] == 0) return;
    visited[x] = 1;
    if (scc[x].size() == 0) {
        tongl[x] = 1;
        return;
    }
    for (auto diemke: scc[x]) {
        dfs(diemke);
        tongl[x] += tongl[diemke];
    }
    ans += sum[x] * tongl[x];
    if (sum[x] > 1) ans += sum[x] * sum[x];
}
void solve()
{
    cin>>n>>m;
    coins.resize(0); coins.resize(n+5);
    for (ll i=1; i<=n; i++) coins[i]=1;
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        if (u == v) {
            ans++;
            continue;
        }
        adj[u].push_back(v);
        back_adj[v].push_back(u);
    }
 
    
    //sap sep topo
    visited.resize(0); visited.resize(n+5, false);
    for (ll i=1; i<=n; i++) if (visited[i]==false) dfs(i);
    reverse(topo.begin(), topo.end());
 

    //tim thanh phan lien thong manh va nen thanh do thi moi
    sum.resize(0); sum.resize(n+5, 0);
    visited.resize(0); visited.resize(n+5, false);
    c.resize(0); c.resize(n+5);
    for (auto i: topo) if (visited[i]==false) 
    {
        component.clear();
        dfs2(i);
        ++k;
        for (auto v: component) 
        {
            sum[k]+=coins[v];
            c[v]=k;
        }
    }
    for (ll u=1; u<=n; u++) 
        for (auto v: adj[u]) if (c[u]!=c[v]) scc[c[u]].push_back(c[v]);






    // cout<<k<<endl;
    // for (ll i=1; i<=k; i++)
    // {
    //     cout<<"i = "<<i<<"     size = "<<sum[i]<<"        ke = ";
    //     for (auto j: scc[i]) cout<<j<<" ";  cout<<endl;
    // }

 
    // dp.resize(0); dp.resize(n+5, 0);
    // visited.resize(0); visited.resize(n+5, false);
    // for (ll i=1; i<=k; i++) if (visited[i]==false) dfs3(i);
    // cout<<*max_element(dp.begin(), dp.end());
    for (int i = 1; i <= k; i++) visited[i] = 0;
    for (int i = 1; i <= k; i++) {
        dfsloc(i);
    }
    cout << ans << endl;
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