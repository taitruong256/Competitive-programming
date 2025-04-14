/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n; 
ll xs, ys, xt, yt;
char a[60][60];
bool visited[60][60];
ll xx[]={-1, 1, 0, 0}, yy[]={0, 0, 1, -1};
set<pair<ll, ll>> st[2];

void dfs(ll x, ll y, ll pos)
{                   
    if (x<1 || x>n || y<1 || y>n || visited[x][y]==true ||a[x][y]=='1') return;
    visited[x][y]=true;
    st[pos].insert(make_pair(x, y));
    for (ll k=0; k<4; k++) dfs(x+xx[k], y+yy[k], pos);
}

void solve()
{
    cin>>n;
    cin>>xs>>ys>>xt>>yt;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) cin>>a[i][j];
    
    memset(visited, false, sizeof(visited));
    dfs(xs, ys, 0);
    memset(visited, false, sizeof(visited));
    dfs(xt, yt, 1);

    ll ans=1e9;
    for (auto i: st[0])
        for (auto j: st[1]) ans=min(ans, (j.first-i.first)*(j.first-i.first)+(j.second-i.second)*(j.second-i.second));
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
