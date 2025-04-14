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
vector<bool> used;
vector<ll> d, parent;

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
    d.resize(n+5, INF);
    parent.resize(n+5, -1);
    priority_queue<  pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>  > pq;
    vector<edge> caykhung;
    pq.push({0, u});
    ll ans=0;

    while (!pq.empty())
    {
        pair<ll, ll> top=pq.top(); pq.pop();
        ll dinh=top.second, trongso=top.first;

        if (used[dinh]==true) continue;
        if (dinh!=u) caykhung.push_back({dinh, parent[dinh], trongso});
        used[dinh]=true;
        ans+=trongso;
        for (auto it: canh[dinh]) if (used[it.first]==false && it.second<d[it.first]) 
        {
            d[it.first]=it.second;
            pq.push({it.second, it.first});
            parent[it.first]=dinh;
        }
        //debugg(pq);
    }
    cout<<ans<<endl;
    //for (auto it: caykhung) cout<<it.u<<" "<<it.v<<" "<<it.w<<endl;
}

void solve()
{
    cin>>n>>m;
    canh.resize(n+5);
    for (ll i=0; i<m; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        canh[u].push_back({v, w});
        canh[v].push_back({u, w});
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