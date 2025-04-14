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
const ll inf = 1e18;
ll n, m, d[100005], trace[100005];
vector<pair<ll, ll>> adj[100005];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
bool vis[100005];

void dijktra(ll s)
{
    for (ll i=0; i<=n; i++) d[i]=inf;
    pq.push({0, s});
    d[s]=0;

    while (!pq.empty())
    {
        auto [wu, u]=pq.top();
        pq.pop();
        if (wu>d[u]) continue;
        vis[u]=true;
        for (auto [v, w]: adj[u]) if (vis[v]==false && d[u]+w<d[v])
        {
            d[v]=d[u]+w;
            pq.push({d[v], v});
            trace[v]=u;
        }
    }
}

void solve()
{
    cin>>n>>m;    
    for (ll i=0; i<m; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijktra(0);
    cout<<d[4];
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