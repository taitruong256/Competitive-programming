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

void solve()
{
    ll n, m, k; cin>>n>>m>>k;
    map<ll, vector<pair<ll, ll>>> adj;
    vector<bool> vis(n+5, false);
    vector<ll> a;
    for (ll i=1; i<=m; i++)
    {
        ll u, v, c; cin>>u>>v>>c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    for (ll i=1; i<=k; i++)
    {
        ll x; cin>>x;
        a.push_back(x);
        vis[x]=true;
    }
    ll ans=1e18;
    for (auto x: a) if (vis[x]==true)
    {
        for (auto v: adj[x]) if (vis[v.first]==false)
        {
            ans=min(ans, v.second);
        }
    }
    if (ans==1e18) cout<<-1;
    else cout<<ans;
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