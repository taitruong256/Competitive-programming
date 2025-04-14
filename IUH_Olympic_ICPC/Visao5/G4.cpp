#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e18;
ll n, m, ans=0;
bool vis[1000], fi;
vector<ll> adj[1000];

void dfs(ll u, ll p)
{
    vis[u]=true;
    if (u==p && fi==true) vis[u]=false;
    fi=false;
    for (ll v: adj[u]) if (vis[v]==false) dfs(v, u);
}

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
    }

    for (ll i=1; i<=n; i++)
    {
        for (ll j=1; j<=n; j++) vis[j]=false;
        fi=true;
        dfs(i, i);
        for (ll j=1; j<=n; j++) if (vis[j]==true) ++ans;
    }
    cout<<ans;
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