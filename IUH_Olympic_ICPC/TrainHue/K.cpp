/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dx[4]={0, 0, 1, -1}, dy[4]={1, -1, 0, 0};
bool visited[1005][1005];
ll n, m; 
char a[1005][1005];

void dfs(ll x, ll y)
{              // cout<<x<<" "<<y<<endl;
    a[x][y]='#';
    for (ll i=0; i<4; i++)
    {
        ll x1=x+dx[i], y1=y+dy[i];
        if (x1>=1 && x1<=n && y1>=1 && y1<=m && a[x1][y1]=='.') dfs(x1, y1);
    }
}

void solve()
{
    cin>>n>>m;
    memset(visited, false, sizeof(visited));

    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) cin>>a[i][j];

    ll ans=0;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) if (a[i][j]=='.')
        {
            dfs(i, j);
            ++ans;
        }

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