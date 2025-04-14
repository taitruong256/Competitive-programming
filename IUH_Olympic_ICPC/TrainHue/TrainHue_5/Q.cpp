#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<bool> dau;
vector<vector<pair<ll, ll>>> ke;
vector<ll> d;
vector<vector<ll>> truyvet;
ll INF=1e18, cnt=0;

void truoc(ll u)
{    cout<<u<<" ";
    if (u==0)
    {
        ++cnt;
        return;
    }

    for (auto it: truyvet[u]) truoc(it);
}

void debugg(priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq)
{
    while (!pq.empty())
    {
        pair<ll, ll> dinh=pq.top();
        pq.pop();
        cout<<dinh.first<<" "<<dinh.second<<endl;
    }
}

void solve(ll s)
{
    ll n, m; cin>>n>>m;
    ke.resize(0); ke.resize(n+5);
    truyvet.resize(0); ke.resize(n+5);
    dau.resize(0); dau.resize(n+5, false);
    d.resize(0); d.resize(n+5, INF);
    truyvet[s].push_back(-1);

    for (ll i=0; i<m; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        ke[u].push_back({v, w});
        ke[v].push_back({u, w});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, s});
    d[0]=0;
    while (!pq.empty())
    {
        pair<ll, ll> dinh=pq.top(); pq.pop();
        ll u=dinh.second;
        if (dau[u]==true) continue;
        for (auto v: ke[u]) if (dau[v.second]==false)
        {
            ll k=v.first, trongso=v.second;
            if (d[u]+trongso<d[k])
            {
                d[k]=d[u]+trongso;
                pq.push({d[k], k});
                truyvet[k].push_back(u);
            }
        }
        //debugg(pq);
    }
    for (ll i=0; i<n; i++)
    {
        for (ll j=0; j<truoc[i].size(); j++) cout<<truyvet[i][j]<<" ";
        cout<<endl;
    }
    cout<<d[n-1];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    solve(0);
    return 0;
}
