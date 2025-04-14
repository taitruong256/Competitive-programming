/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, l, mi;
vector<ll> edge[1005];
struct pipe{ll first, last, d;};
vector<pipe> ans;
bool visited[1005];
ll d[1005];

void dfs(ll x)
{     
    l=x;
    mi=min(mi, d[x]);
    visited[x]=true;
    for (auto i: edge[x]) dfs(i);
}

void solve()
{
    cin>>n>>m;
    memset(visited, false, sizeof(visited));
    for (ll i=1;i<=n; i++) d[i]=1e9;
    for (ll i=1; i<=m; i++)
    {
        ll a, b; cin>>a>>b;
        cin>>d[b];
        visited[b]=true;
        edge[a].push_back(b);
    }                 

    for (ll i=1; i<=n; i++) if (!visited[i])
    {
        mi=1e9;
        dfs(i);
        if (mi!=1e9) ans.push_back({i, l, mi});
    }

    cout<<ans.size()<<endl;
    for (ll i=0; i<ans.size(); i++) cout<<ans[i].first<<" "<<ans[i].last<<" "<<ans[i].d<<endl;
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
