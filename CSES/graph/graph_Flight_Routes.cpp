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
ll n, m, k; 
map<ll, vector<pair<ll, ll>>> adj;
vector<ll> dist, cnt;

void debugg(priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq)
{
    while (!pq.empty())
    {
        pair<ll, ll> dinh=pq.top();
        pq.pop();
        cout<<dinh.first<<" "<<dinh.second<<endl;
    }
    cout<<endl;
}

void dijktra(ll s)
{
    dist.resize(0); dist.resize(n+5, inf);
    cnt.resize(0); cnt.resize(n+5, 0);    

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist[s]=0;
    pq.push({0, s});
    while (!pq.empty() && cnt[n]<k)
    {              //debugg(pq);
        pair<ll, ll> dinh=pq.top(); pq.pop();
        ll u=dinh.second, trongso=dinh.first;
        ++cnt[u];
        if (u==n) cout<<trongso<<" ";
        if (cnt[u]<=k)
        {
            for (auto e: adj[u])
            {
                ll v=e.first, w=e.second;
                pq.push({trongso+w, v});
            }
        }
    } 
}

void solve()
{
    cin>>n>>m>>k;
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