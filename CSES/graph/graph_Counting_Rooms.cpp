/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const ll mod = 1e9+7;
const ll inf = 1e9;
ll n, m;
char c[1005][1005];
ll dx[]={0, 0, 1, -1}, dy[]={1, -1, 0, 0};

void dfs(ll x, ll y)
{
    if (x<1 || x>n || y<1 || y>m || c[x][y]=='#') return;
    c[x][y]='#';
    for (ll i=0; i<4; i++) dfs(x+dx[i], y+dy[i]);
}

void solve()
{
    cin>>n>>m; 
    ll ans=0;
    for (ll i=1; i<=n; i++) 
        for (ll j=1; j<=m; j++) cin>>c[i][j];
    
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) if (c[i][j]=='.')
        {
            ++ans;
            dfs(i, j);
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