/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ans=0;
vector<pair<ll, ll>> edge[105];
bool visited[10005];

void dfs(ll x, ll cost) 
{    
    visited[x]=true;
    ans=max(ans, cost);
    for (auto i: edge[x]) if (visited[i.first]==false) dfs(i.first, cost+i.second); 
}

void solve()
{
    cin>>n;
    memset(visited, false, sizeof(visited));
    for (ll i=1; i<n; i++)
    {
        ll u, v, c; cin>>u>>v>>c;
        edge[u].push_back({v, c});
        edge[v].push_back({u, c});
    }
    dfs(0, 0);
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
