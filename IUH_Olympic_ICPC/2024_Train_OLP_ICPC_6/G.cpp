/*==============================================================================================================
         __                    __                                             _____     ______    _______
        |  |                  |  |                                           /  __ \   / _____|  / ______|     
      __|  |__              __|  |__                                         |_|  | |  | |       | |  
     |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
        |  |    _____   _     |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
        |  |_  | |_| | | |    |  |_  | |   | |_| | | |_| | | |  | | | |_| |    / /___   ____| |  | |___| |
        \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  |_| \____ |   |______| |______/  \_______/
                                                                        | |
                                                                      __/ |
                                                                     |___/  
                                        Pratice, practice, and practice
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
     Laziness is only temporary comfort. The future will regret that day. Don't fall into the trap of comfort.
                The most beautiful meeting in this world is meeting the best version of yourself.
                          Practice doing things you don't like but are useful to you
                                   Success is born from problem solving
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll int 
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

char c[55][55];
ll n, m, dis[55][55] ,vis[55][55], id[55][55], idx=0;
ll dx[]={-1, 1, 0, 0}, dy[]={0, 0, -1, 1};
ll dp[1LL<<16][16];

void dfs(ll u, ll v)
{
    queue<pair<ll, ll>> q;
    q.push({u, v});
    vis[u][v]=0;
    while (!q.empty())
    {
        auto [x, y]=q.front(); q.pop();
        id[x][y]=idx;
        for (ll i=0; i<4; i++)
        {
            ll newx=x+dx[i], newy=y+dy[i];
            if (1<=newx && newx<=n && 1<=newy && newy<=m && vis[newx][newy]==-1 && c[newx][newy]=='X') 
            {
                vis[newx][newy]=0;
                q.push({newx, newy});
            }
        }
    }
    ++idx;
}

void bfs(ll u, ll v)
{
    for (ll i=0; i<=n; i++)
        for (ll j=0; j<=m; j++) vis[i][j]=-1;

    queue<pair<ll, ll>> q;
    q.push({u, v});
    vis[u][v]=0;
    while (!q.empty())
    {
        auto [x, y]=q.front(); q.pop();
        if (c[x][y]=='X') dis[id[u][v]][id[x][y]]=vis[x][y];
        for (ll i=0; i<4; i++)
        {
            ll newx=x+dx[i], newy=y+dy[i];
            if (1<=newx && newx<=n && 1<=newy && newy<=m && vis[newx][newy]==-1 && c[newx][newy]!='.') 
            {
                vis[newx][newy]=vis[x][y]+(c[newx][newy]=='S');
                q.push({newx, newy});
            }
        }
    }
}

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++)
            cin>>c[i][j];

    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) vis[i][j]=id[i][j]=-1;

    for (ll i=1; i<=n; i++) 
        for (ll j=1; j<=m; j++) 
            if (c[i][j]=='X' && vis[i][j]==-1) dfs(i, j); 
    
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++)
            if (c[i][j]=='X')
                bfs(i, j);

    for (ll i=1; i<=n; i++) 
    {
        for (ll j=1; j<=m; j++) cout<<id[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;

    for (ll i=0; i<idx; i++) 
    {
        for (ll j=0; j<idx; j++) cout<<dis[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;

    n=idx; 
    assert(n<=15); 
    for (ll mask=0; mask<(1LL<<n); mask++) 
        for (ll i=0; i<n; i++) 
            dp[mask][i]=1e9; 

    for (ll i=0; i<n; i++) dp[(1<<i)][i]=0; 

    for (ll mask=0; mask<(1<<n); mask++) 
    {
      for (ll u=0; u<n; u++) if (mask&(1<<u)) 
      {
        ll old_mask=mask^(1<<u);   
        for (ll v=0; v<n; v++) if (old_mask&(1<<v) && u!=v) 
        {   
          dp[mask][u]=min(dp[old_mask][v]+dis[v][u], dp[mask][u]);
        }
      }
    }

    ll ans=1e9;
    for (ll i=0; i<n; i++) ans=min(ans, dp[(1<<n)-1][i]);
    if (ans==1e9) ans=-1;
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    solve();
    return 0;
}