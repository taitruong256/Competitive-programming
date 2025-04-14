/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, cnt;
vector<pair<ll, ll>> edge[200];
bool visited[200];

void dfs(ll s, ll color)
{                   
    visited[s]=true;
    for (auto it: edge[s]) if (it.second==color && visited[it.first]==false) dfs(it.first, color);
}

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=m; i++)
    {
        ll u, v, c; cin>>u>>v>>c;
        edge[u].push_back({v, c});
        edge[v].push_back({u, c});
    }
    
    ll q; cin>>q;
    while (q--)
    {
        ll u, v; cin>>u>>v;
        cnt=0;
        for (ll i=1; i<=m; i++) 
        {
            memset(visited, false, sizeof(visited));
            dfs(u, i);
            if (visited[v]==true) ++cnt;
        }
        cout<<cnt<<endl;
    }
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
