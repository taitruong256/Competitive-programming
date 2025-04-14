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
ll n, m, q;
vector<ll> d[105], trace[105], duongdi;
vector<bool> visited;
vector<vector<pair<ll, ll>>> canh;

void truyvet(ll u, ll v)
{             
    if (u==v) return;
    truyvet(u, trace[u][v]);
    duongdi.push_back(v);
}

void dijktra(ll s)
{
    visited.resize(n+5, false);
    d[s].resize(n+5, INF);
    trace[s].resize(n+5, -1);
    
    d[s][s]=0;
    priority_queue<   pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>  > pq;
    pq.push({0, s});
    while (!pq.empty())
    {
        pair<ll, ll> x=pq.top();
        pq.pop();
        ll u=x.second;
        if (visited[u]==true) continue;
        for (auto e: canh[u]) //if (visited[e.first]==false)
        {
            ll v=e.first, w=e.second;
            if (d[s][u]+w<d[s][v]) 
            {
                d[s][v]=d[s][u]+w;
                pq.push({d[s][v], v});
                trace[s][v]=u;
            }
        }
    }
}

void solve()
{
    cin>>n>>m>>q;
    canh.resize(n+5);
    for (ll i=1; i<=m; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        canh[u].push_back({v, w});
        canh[v].push_back({u, w});
    }

    // for (auto i: canh)
    // {
    //     for (auto j: i) cout<<j.first<<" "; 
    //     cout<<endl;
    // }
    for (ll i=1; i<=n; i++) dijktra(i);

    for (ll i=0; i<q; i++) 
    {
        ll t, x, y; cin>>t>>x>>y;
        
        if (t==0) cout<<d[x][y]<<endl;
        else if (t==1)
        {
            duongdi.resize(0);
            duongdi.push_back(x);
            truyvet(x, y);
            cout<<duongdi.size()<<" ";
            for (auto j: duongdi) cout<<j<<" ";
            cout<<endl;
        }
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