#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e18;

vector<ll> adj[100005];
ll a[100005], d[100005];

void solve()
{
    ll n, m, k; cin>>n>>m>>k;
    for (ll i=1; i<=k; i++) cin>>a[i];
    for (ll i=1; i<=m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[v].push_back(u);
    }


    queue<ll> q;
    for (ll i=1; i<=n; i++) d[i]=-1;
    for (ll i=1; i<=k; i++) q.push(a[i]), d[a[i]]=0;
    

    while (!q.empty())
    {
        ll u=q.front(); q.pop();
        for (ll v: adj[u]) if (d[v]==-1)
        {
            d[v]=d[u]+1;
            q.push(v);
        }
    }
    for (ll i=1; i<=n; i++) cout<<d[i]<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}