/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, ans=1, cur;
vector<ll> edge[55];
bool visited[55];

void dfs(ll x)
{                   
    visited[x]=true;
    for (auto i: edge[x]) if (visited[i]==false) 
    {
        ans*=2;
        dfs(i);
    }
}

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=m; i++)
    {
        ll u, v; cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    memset(visited, false, sizeof(visited));
    for (ll i=1; i<=n; i++) if (visited[i]==false) dfs(i);
    cout<<ans;
}
 
int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;
    while (t--) solve();
    return 0;
}
