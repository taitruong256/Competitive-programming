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
struct edge{ll u, v, w;};
ll n, m;
map<ll, vector<pair<ll,ll>>> adj1, adj2;
vector<ll> dist1, distn;
vector<edge> E;

vector<ll> dijktra(ll s, vector<ll> dist, map<ll, vector<pair<ll, ll>>> adj)
{
    dist.resize(0); dist.resize(n+5, inf);
    dist[s]=0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq; 
    pq.push({0, s});       

    while (!pq.empty())
    { 
        pair<ll, ll> dinh=pq.top(); pq.pop();
        ll u=dinh.second, trongso=dinh.first;
        if (trongso>dist[u]) continue;
        for (auto e: adj[u])
        {
            ll v=e.first, w=e.second;
            if (dist[u]+w<dist[v]) 
            {
                dist[v]=dist[u]+w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

void solve()
{
    cin>>n>>m;      
    for (ll i=0; i<m; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        adj1[u].push_back({v, w});
        adj2[v].push_back({u, w});
        E.push_back({u, v, w});
    }             
    dist1=dijktra(1, dist1, adj1);
    distn=dijktra(n, distn, adj2);
    ll ans=inf;
    for (auto e: E) ans=min(ans, dist1[e.u]+e.w/2+distn[e.v]);
    cout<<ans;
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