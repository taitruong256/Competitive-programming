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
map<ll, vector<ll>> adj;
vector<bool> visited;
vector<ll> sz;
ll n;

void dfs(ll u, ll h)
{
    sz[h]++;
    visited[u]=true;
    for (auto v: adj[u]) if (visited[v]==false) dfs(v, h+1);
}

void solve()
{
    
    cin>>n;
    for (ll i=2; i<=n; i++)
    {
        ll x; cin>>x;
        adj[x].push_back(i);
    }
    visited.resize(0); visited.resize(n+5, false);
    sz.resize(0);; sz.resize(n+5, 0);
    dfs(1, 0);
    ll ans=0;
    for (ll i=0; i<n; i++) ans+=sz[i]%2;
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