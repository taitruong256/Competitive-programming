/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18+7;
ll n, m, a, b; 
vector<ll> d;
vector<bool> visited;
vector<vector<pair<ll, ll>>> canh;

void dijktra(ll s)
{
    visited.resize(0);
    visited.resize(n+5, false);
    d.resize(0);
    d.resize(n+5, INF);
    
    
    d[s]=0;
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
            if (d[u]+w<d[v]) 
            {
                d[v]=d[u]+w;
                pq.push({d[v], v});
            }
        }
    }
}

void solve()
{
    cin>>n>>m;
    cin>>a>>b;  
    canh.resize(n+5);
    for (ll i=1; i<=m; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        canh[u].push_back({v, w});
        canh[v].push_back({u, w});
    }
    ll ans=0;
    dijktra(1);
    if (d[a]==INF) ans=INF;
    if (d[a]!=INF && ans!=INF) ans+=d[a];
    dijktra(a);
    if (d[b]==INF) ans=INF;
    if (d[b]!=INF && ans!=INF) ans+=d[b];
    dijktra(b);
    if (d[n]==INF) ans=INF;
    if (d[n]!=INF && ans!=INF) ans+=d[n];

    ll ans2=0;
    dijktra(1);
    if (d[b]==INF) ans2=INF;
    if (d[b]!=INF && ans2!=INF) ans2+=d[b];
    dijktra(b);
    if (d[a]==INF) ans2=INF;
    if (d[a]!=INF && ans2!=INF) ans2+=d[a];
    dijktra(a);
    if (d[n]==INF) ans2=INF;
    if (d[n]!=INF && ans2!=INF) ans2+=d[n];

    ans=min(ans, ans2);
    if (ans!=INF) cout<<ans;
    else cout<<"IMPOSSIBLE";
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