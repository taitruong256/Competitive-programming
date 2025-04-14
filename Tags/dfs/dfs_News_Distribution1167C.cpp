/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, cnt, now; 
vector<ll> a[500005];
bool visited[500005];
ll ans[500005];

void dfs(ll x)
{
    visited[x]=true;
    ans[x]=-now;
    ++cnt;
    for (auto it: a[x]) if (visited[it]==false) dfs(it);
}

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=m; i++) 
    {
        ll k; cin>>k;
        if (k==0) continue;
        ll u, v; cin>>u;
        for (ll j=1; j<=k-1; j++)
        {
            cin>>v;     
            a[u].push_back(v);
            a[v].push_back(u);
        }
    }

    // for (ll i=1; i<=n; i++)
    // {  cout<<i<<" |  ";
    //     for (ll j=0; j<a[i].size(); j++) cout<<a[i][j]<<" ";
    //     cout<<endl;
    // }
    // cout<<endl;

    memset(visited, false, sizeof(visited));
    for (ll i=1; i<=n; i++) if (visited[i]==false)
    {
        cnt=0;
        now=i;
        dfs(i);
        ans[i]=cnt;
    }
    for (ll i=1; i<=n; i++) if (ans[i]<0) cout<<ans[-ans[i]]<<" "; else cout<<ans[i]<<" ";
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
