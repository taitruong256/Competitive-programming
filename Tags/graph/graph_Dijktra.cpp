/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18;
struct edge{ll u, w;};
ll n, m, s;
vector<ll> d, trace, duongdi;
vector<bool> visited;
vector<pair<ll, ll>> canh[100005];

void truyvet(ll u, ll v)
{             
    if (u==v) return;
    truyvet(u, trace[v]);    
    duongdi.push_back(v);
}

void dijktra()
{
    visited.resize(n+5, false);
    d.resize(n+5, INF);
    trace.resize(n+5, -1);
    
    d[s]=0;
    priority_queue<   pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>  > pq;
    pq.push({0, s});
    while (!pq.empty())
    {
        pair<ll, ll> x=pq.top();
        pq.pop();
        ll u=x.second;
        if (visited[u]==true) continue;
        for (auto e: canh[u]) if (visited[e.first]==false)
        {
            ll v=e.first, w=e.second;
            if (d[u]+w<d[v]) 
            {
                d[v]=d[u]+w;
                pq.push({d[v], v});
                trace[v]=u;
            }
        }
    }
}

void solve()
{
    cin>>n>>m>>s;
    for (ll i=1; i<=m; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        canh[u].push_back({v, w});
    }
    dijktra();
    for (ll i=0; i<n; i++) 
    {
        if (d[i]==1e18) d[i]=-1;
        cout<<d[i]<<"        ";
        duongdi.resize(0);
        duongdi.push_back(s);
        truyvet(s, i);
        for (auto j: duongdi) cout<<j<<" ";
        cout<<endl;
    }
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