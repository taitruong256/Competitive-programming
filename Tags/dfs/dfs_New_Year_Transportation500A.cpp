/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, t;
ll a[30005];
bool visited[30005];

void dfs(ll x) 
{    
    visited[x]=true;
    if (x<n) dfs(x+a[x]);
}

void solve()
{
    memset(visited, false, sizeof(visited));
    cin>>n>>t;
    for (ll i=1; i<=n-1; i++) cin>>a[i];
    dfs(1);
    if (visited[t]==true) cout<<"YES"; else cout<<"NO";
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
