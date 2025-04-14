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
 
void bfs(ll x, ll y)
{
    queue<pair<ll, ll>> q;
    q.push({x, y});
    c[x][y]='#';
    
    while (!q.empty())
    {
        auto [xx, yy]=q.front(); 
        q.pop();
        for (ll i=0; i<4; i++)
        {
            ll new_x=xx+dx[i], new_y=yy+dy[i];
            if (new_x>=1 && new_x<=n && new_y>=1 && new_y<=m && c[new_x][new_y]=='.')
            {
                q.push({new_x, new_y});
                c[new_x][new_y]='#';
            }
        }
    }
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
            bfs(i, j);
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