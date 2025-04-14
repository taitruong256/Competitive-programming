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
map<ll, vector<pair<ll, ll>>> adj;
vector<bool> visited;
ll res=0;

void dfs(int v, int p) 
{
    if (v == 1 && p) return;
    for (auto u: adj[v])
        if (u.first != p) 
        {
            res += u.second;
            dfs(u.first, v);
            return;
        }
}

void solve()
{
    ll n; cin>>n;
    ll sum=0;
    for (ll i=0; i<n; i++)
    {
        ll u, v, c; cin>>u>>v>>c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, 0});
        sum+=c;
    }
    visited.resize(0); visited.resize(n+5, false);
    dfs(1, 0);
    cout<<min(res, sum-res);
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