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
struct edge{ll u, v, w;};
ll n, m;
vector<vector<pair<ll, ll>>> canh;
vector<ll> parent, d; 
vector<bool> used;
vector<edge> caykhung;

void debugg(priority_queue<  pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>  > pq)
{
    while (!pq.empty())
    {
        auto top=pq.top(); pq.pop();
        cout<<top.first<<" "<<top.second<<endl;
    }
    cout<<endl;
}

void prim(ll u)
{  
    used.resize(n+5, false);
    parent.resize(n+5, -1);
    d.resize(n+5, INF);

    priority_queue<  pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>  > pq;
    pq.push({0, u});
    used[u]=true;
    d[u]=0;
    ll ans=0;

    while (!pq.empty())
    {
        pair<ll, ll> top=pq.top(); pq.pop();
        ll dinh=top.second, trongso=top.first;
        if (trongso!=d[dinh]) continue;
        ans+=trongso;
        used[dinh]=true;
        if (dinh!=u) caykhung.push_back({dinh, parent[dinh], trongso});
        for (auto it: canh[dinh]) if (used[it.first]==false && it.second<d[it.first])
        {
            pq.push({it.second, it.first});
            d[it.first]=it.second;
            parent[it.first]=dinh;
        }        
        debugg(pq);
    }

    cout<<ans<<endl;
    for (auto it: caykhung) cout<<it.u<<" "<<it.v<<" "<<it.w<<endl;
}

void solve()
{
    cin>>n>>m;
    canh.resize(m+5);
    for (ll i=0; i<m; i++)
    {
        ll x, y, w; cin>>x>>y>>w;
        canh[x].push_back({y, w});
        canh[y].push_back({x, w});
    }
    prim(1);
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