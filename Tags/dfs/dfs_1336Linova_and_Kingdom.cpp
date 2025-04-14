/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, vector<ll>> ke;
ll n, k;
ll depth[100005], sz[100005], f[100005];
bool dau[100005];

void dfs(ll u, ll parent)
{             //   cout<<u<<endl;
    depth[u]=depth[parent]+1;
    sz[u]=1;
    for (auto v: ke[u]) if (v!=parent)
    {
        dfs(v, u);
        sz[u]+=sz[v];
    }
}

void solve()
{
    cin>>n>>k;
    for (ll i=0; i<n-1; i++)
    {
        ll u, v; cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    //memset(sz, 0, szof(sz));
    //memset(depth, 0, szof(depth));
    // memset(dau, false, szof(dau));
    depth[0]=0;
    sz[0]=0;
    dfs(1, 0);
    for (ll i=1; i<=n; i++) f[i]=depth[i]-sz[i];
    // for (ll i=1; i<=n; i++) cout<<depth[i]<<" "; cout<<endl;
    // for (ll i=1; i<=n; i++) cout<<sz[i]<<" "; cout<<endl;
    // for (ll i=1; i<=n; i++) cout<<f[i]<<" "; cout<<endl;
    sort(f+1, f+n+1, greater<ll>());
    ll ans=0;
    for (ll i=1; i<=k; i++) ans+=f[i];
    cout<<ans;
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