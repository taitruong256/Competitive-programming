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

void solve()
{
    ll n, m; cin>>n>>m;
    visited.resize(0);
    visited.resize(n+5, false);
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    pq.push(1);
    visited[1]=true;
    vector<ll> ans;
    while (!pq.empty())
    {
        ll u=pq.top(); pq.pop();
        ans.push_back(u);
        for (auto v: adj[u]) if (visited[v]==false)
        {
            pq.push(v);
            visited[v]=true;
        }
    }
    for (auto it: ans) cout<<it<<" ";
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