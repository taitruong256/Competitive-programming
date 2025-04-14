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
map<ll, vector<pair<ll, ll>>> adj;
vector<ll> d, parent, ans;
ll n, m;

void debugg(priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq)
{
    while (!pq.empty())
    {
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
    }
}
 
void trace(ll u)
{
    while (u!=0)
    {
        ans.push_back(u);
        u=parent[u];
    }
    reverse(ans.begin(), ans.end());
}
 
void dijktra(ll s)
{
    d.resize(0); d.resize(n+5, inf);
    vector<bool> visited(n+5, false);
    parent.resize(0); parent.resize(n+5, 0);
    d[s]=0; 
 
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, s});
    while (!pq.empty())
    {                   debugg(pq); cout<<endl;
        pair<ll, ll> top=pq.top(); pq.pop();
        ll u=top.second, trongso=top.first;// cout<<u<<endl;
        if (trongso>d[u]) continue;
        visited[u]=true;
        for (auto e: adj[u])
        {
            ll v=e.first, w=e.second;
            if (d[u]+w<d[v])
            {
                d[v]=d[u]+w;
                parent[v]=u;
                pq.push({d[v], v});
            }
        }
    }
}
 
void solve()
{
    cin>>n>>m;  
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back({v, -1});
    }
    dijktra(1);
    // cout<<d[n]<<endl;
    if (d[n]==inf) cout<<"IMPOSSIBLE";
    else 
    {
        trace(n);
        cout<<ans.size()<<endl;
        for (auto it: ans) cout<<it<<" ";
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