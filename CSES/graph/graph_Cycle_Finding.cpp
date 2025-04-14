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
struct edge{ll u, v, w;};
vector<edge> E;
vector<ll> dist, parent, path;
ll n, m, st;

void Bellman_Ford(ll s)
{
    dist.resize(0); dist.resize(n+5, inf);
    parent.resize(0); parent.resize(n+5, 0);
    dist[s]=0;
    for (ll i=1; i<=n; i++)
    {
        st=-1;
        for (auto e: E) if (dist[e.u]+e.w<dist[e.v])
        {
            dist[e.v]=dist[e.u]+e.w;
            st=e.v;
            parent[e.v]=e.u;
        }
    }
}

void truyvet(ll st)
{
    for (ll i=1; i<=n; i++) st=parent[st];
    ll fi=st;
    while (true)
    {
        if (fi==st && path.size()>1) break;
        path.push_back(fi);
        fi=parent[fi];
    }
    reverse(path.begin(), path.end());
    path.push_back(path.front());
}

void solve()
{
    cin>>n>>m;
    for (ll i=0; i<m; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        E.push_back({u, v, w});
    }
    Bellman_Ford(1);
    if (st==-1) cout<<"NO";
    else 
    {
        cout<<"YES\n";
        truyvet(st);
        for (auto i: path) cout<<i<<" "; cout<<endl;
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