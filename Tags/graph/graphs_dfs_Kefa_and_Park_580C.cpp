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
ll n, k, ans=0; 
map<ll, vector<ll>> adj;
vector<bool> visited;
vector<ll> a;

void dfs(ll u, ll m)
{         
    if (m>k) return;
    ll ok=1;
    visited[u]=true;
    for (auto v: adj[u]) if (visited[v]==false)
    {
        ok=0;
        dfs(v, m*a[v]+a[v]);
    }
    ans+=ok;
}

void solve()
{
    cin>>n>>k;
    visited.resize(0); visited.resize(n+5, false);
    a.resize(0); a.resize(n+5);
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=0; i<n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, a[1]);
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}