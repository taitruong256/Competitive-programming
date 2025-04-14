/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, mi=1e10, ans=0;
ll c[100005];
vector<ll> e[100005];
bool visited[100005];

void dfs(ll x) 
{   
    visited[x]=true;
    mi=min(mi, c[x]);          //cout<<x<<" "<<c[x]<<" "<<mi<<endl;
    for (auto it: e[x]) if (visited[it]==false) dfs(it);
}

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=n; i++) cin>>c[i];
    for (ll i=1; i<=m; i++)
    {
        ll u, v; cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    memset(visited, false, sizeof(visited));
    for (ll i=1; i<=n; i++) if (visited[i]==false) 
    {
        mi=1e10;
        dfs(i);
        ans+=mi;
    }
    cout<<ans;
}
 
int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; //cin>>t;
    while (t--) solve();
    return 0;
}
