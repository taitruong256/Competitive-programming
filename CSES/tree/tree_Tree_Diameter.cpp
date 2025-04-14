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
vector<ll> height;
vector<bool> visited;

void bfs(ll s)
{
    queue<ll> q;
    q.push(s);
    visited[s]=true;
    while (!q.empty())
    {
        ll u=q.front(); q.pop();
        for (auto v: adj[u]) if (visited[v]==false)
        {
            q.push(v);
            visited[v]=true;
            height[v]=height[u]+1;
        }
    }
}

void solve()
{
    cin>>n;
    for (ll i=0; i<n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    visited.resize(0); visited.resize(n+5, false);
    height.resize(0); height.resize(n+5, 0);
    bfs(1);
    ll x=1;
    for (ll i=1; i<=n; i++) if (height[i]>height[x]) x=i;
    visited.resize(0); visited.resize(n+5, false);
    height.resize(0); height.resize(n+5, 0);
    bfs(x);
    cout<<*max_element(height.begin(), height.end());
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