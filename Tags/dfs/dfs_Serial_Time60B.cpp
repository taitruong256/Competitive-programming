/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k, n, m, ans=0;
char a[15][15][15];
bool visited[15][15][15];

void dfs(ll x, ll y, ll z) 
{           
    if (a[x][y][z]=='#' || x<1 || x>k || y<1 || y>n || z<1 || z>m) return;
    if (visited[x][y][z]==true) return;
    a[x][y][z]='#';
    visited[x][y][z]=true;
    ++ans;    
    dfs(x, y, z+1);
    dfs(x, y, z-1);
    dfs(x+1, y, z);
    dfs(x-1, y, z);
    dfs(x, y+1, z);
    dfs(x, y-1, z);
}

void solve()
{
    cin>>k>>n>>m;
    for (ll i=0; i<15; i++)
        for (ll j=0; j<15; j++)
            for (ll l=0; l<15; l++) visited[i][j][l]=false;

    for (ll i=1; i<=k; i++)
        for (ll j=1; j<=n; j++)
            for (ll l=1; l<=m; l++) cin>>a[i][j][l];

    ll x, y; cin>>x>>y;
    dfs(1, x, y);
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
