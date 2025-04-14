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
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

char c[55][55];
ll dis[55][55], vis[55][55], n, m, dx[]={0, 0, 1, -1}, dy[]={-1, 1, 0, 0};

ll bfs()
{
  queue<pair<ll, ll>> q;

  for (ll i=1; i<=n; i++)
    for (ll j=1; j<=m; j++)
      if (c[i][j]=='S')
        q.push({i, j}), vis[i][j]=1, dis[i][j]=0;

  for (ll i=1; i<=n; i++)
    for (ll j=1; j<=m; j++)
      if (c[i][j]=='*')
        q.push({i, j}), vis[i][j]=1;

  while (!q.empty())
  {
    auto [x, y]=q.front(); q.pop();
    for (ll i=0; i<4; i++)
    {
      ll newx=x+dx[i], newy=y+dy[i];
      if (1<=newx && newx<=n && 1<=newy && newy<=m && c[newx][newy]!='X' && c[x][y]!=c[newx][newy])
      {
        if (c[x][y]=='S' && c[newx][newy]=='D')
          return dis[x][y]+1;
        if (c[x][y]=='*') 
        {
          if (c[newx][newy]!='D')
          {
            vis[newx][newy]=1;
            c[newx][newy]=c[x][y];
            q.push({newx, newy});
          }
        }
        else if (c[x][y]=='S')
        {
          if (c[newx][newy]=='.' || c[newx][newy]=='D')
          {
            vis[newx][newy]=1;
            c[newx][newy]=c[x][y];
            q.push({newx, newy});
            dis[newx][newy]=dis[x][y]+1;
          }
        }
      
      }
    }

    // cout<<x<<" "<<y<<endl;
    // for (ll i=1; i<=n; i++)
    // {
    //   for (ll j=1; j<=m; j++) cout<<c[i][j]<<" "; cout<<endl;
    // }
    // cout<<endl;
  }
  return -1;
}

void solve()
{
  cin>>n>>m;
  for (ll i=1; i<=n; i++)
    for (ll j=1; j<=m; j++) 
    {
      dis[i][j]=-1;
      cin>>c[i][j];
    }
  ll ans=bfs();
  if (ans==-1) cout<<"KAKTUS";
  else cout<<ans;
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
  return 0;
}