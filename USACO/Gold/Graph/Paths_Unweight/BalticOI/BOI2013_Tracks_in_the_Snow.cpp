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
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
                                          Noi dau + Suy ngam = Tien bo 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll maxn = 200005;
const ll mod = 1e9+7;
ll n, m, depth[4005][4005], dx[]={0, 0, -1, 1}, dy[]={1, -1, 0, 0}, ans;
char c[4005][4005];

bool check(ll x, ll y)
{
  if (x>=1 && x<=n && y>=1 && y<=m && c[x][y]!='.') return true;
  return false;
}

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=n; i++)
      for (ll j=1; j<=m; j++) cin>>c[i][j];
    deque<pair<ll, ll>> dq;
    dq.push_back({1, 1});
    depth[1][1]=1;
    while (!dq.empty())
    {
      auto [x, y]=dq.front();
      ans=max(ans, depth[x][y]);
      dq.pop_front();
      for (ll i=0; i<4; i++)
      {
        ll new_x=x+dx[i], new_y=y+dy[i];
        if (check(new_x, new_y)==true && depth[new_x][new_y]==0)
        {
          if (c[x][y]==c[new_x][new_y]) 
          {
            depth[new_x][new_y]=depth[x][y];
            dq.push_front({new_x, new_y});
          }
          else 
          {
            depth[new_x][new_y]=depth[x][y]+1;
            dq.push_back({new_x, new_y});
          }
        }
      }
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}