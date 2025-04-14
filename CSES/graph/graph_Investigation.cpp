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
ll n, m;
vector<pair<ll, ll>> adj[100005];
vector<ll> d, min_l, max_l, way;

void debugg(priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq)
{
    while (!pq.empty())
    {
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
    }
}

void dijktra(ll s)
{
    d.resize(0); d.resize(n+5, inf);
    min_l.resize(0); min_l.resize(n+5, inf);
    max_l.resize(0); max_l.resize(n+5, -inf);
    way.resize(0); way.resize(n+5, 0);
    d[s]=min_l[s]=max_l[s]=0;
    way[s]=1;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, s});
    while (!pq.empty())
    {                //    debugg(pq); cout<<endl;
        pair<ll, ll> top=pq.top(); pq.pop();
        ll u=top.second, trongso=top.first;
        if (trongso>d[u]) continue;
        for (auto e: adj[u])
        {
            ll v=e.first, w=e.second;
            if (d[u]+w==d[v])
            {
                way[v]=(way[u]+way[v])%mod;
                min_l[v]=min(min_l[v], min_l[u]+1);
                max_l[v]=max(max_l[v], max_l[u]+1);
            }
            else if (d[u]+w<d[v])
            {
                way[v]=way[u];
                min_l[v]=min_l[u]+1;
                max_l[v]=max_l[u]+1;
                d[v]=d[u]+w;
                pq.push({d[v], v});
            }
        }
    }

    cout<<d[n]<<" "<<way[n]<<" "<<min_l[n]<<" "<<max_l[n];
}

void solve()
{
    cin>>n>>m;
    for (ll i=0; i<m; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
    }
    dijktra(1);
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