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
ll n, m, k, cnt, ans=0, mx=0;
map<ll, vector<ll>> adj;
vector<bool> visited;
vector<ll> gov;

void dfs(ll u)
{
    visited[u]=true;
    ++cnt;
    for (auto v: adj[u]) if (visited[v]==false) dfs(v);
}

void solve()
{
    cin>>n>>m>>k;
    visited.resize(n+5, false);
    gov.resize(n+5);
    for (ll i=0; i<k; i++) cin>>gov[i];
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (ll i=0; i<k; i++) 
    {
        cnt=0;
        dfs(gov[i]);
        mx=max(mx, cnt);
        ans+=cnt*(cnt-1)/2;
    }
    for (ll i=1; i<=n; i++) if (visited[i]==false) ans+=mx++;
    cout<<ans-m;
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