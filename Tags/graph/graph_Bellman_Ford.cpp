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
ll n, m, s; 
vector<edge> canh;
vector<ll> d, trace;

vector<ll> trace_path(ll s, ll v)
{
    if (v!=s && trace[v]==-1) return vector<ll>(0);

    vector<ll> path;
    while (v!=s)
    {
        path.push_back(v);
        v=trace[v];
    }
    reverse(path.begin(),path.end());
    return path;
}

bool TimChuTrinhAm(vector<ll> &path)
{
    ll st=-1;
    for (ll i=0; i<=n-1; i++)
    {
        for (auto e: canh) if (d[e.u]!=INF && d[e.v]>d[e.u]+e.w)
        {
            d[e.v]=d[e.u]+e.w;
            trace[e.v]=e.u;
            st=i;
        }
    }
    if (st==-1) return false;

    ll fi=st;
    for (ll i=0; i<n; i++) fi=trace[fi];
    path.push_back(st);
    for (int v = trace[fi]; v != fi; v = trace[fi]) {
        path.push_back(v); // truy vết một vòng
    }
    reverse(path.begin(), path.end());            cout<<path.size()<<endl;
    return true;
}

void Bellman_Ford()
{
    d.resize(n+5, INF);
    trace.resize(n+5, -1);

    d[s]=0;
    for (ll i=1; i<=n-1; i++)
    {
        for (auto e: canh) if (d[e.u]!=INF && d[e.v]>d[e.u]+e.w)
        {
            d[e.v]=d[e.u]+e.w;
            trace[e.v]=e.u;
        }
    }

    for (ll i=1; i<=n-1; i++)
    {
        for (auto e: canh) if (d[e.u]!=INF && d[e.v]>d[e.u]+e.w)
        {
            d[e.v]=-INF;
            trace[e.v]=e.u;
        }
    }
}

void solve()
{
    cin>>n>>m>>s;
    for (ll i=0; i<m; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        canh.push_back({u, v, w});
    }
    Bellman_Ford();
    for (ll i=0; i<n; i++) 
        if (d[i]==INF) cout<<"Impossible"<<endl;
        else if (d[i]==-INF) cout<<"-Infinity"<<endl;
        else cout<<d[i]<<endl;

    vector<ll> p;
    TimChuTrinhAm(p);
    for (ll i=0; i<p.size(); i++) cout<<p[i]<<" "; cout<<endl;
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