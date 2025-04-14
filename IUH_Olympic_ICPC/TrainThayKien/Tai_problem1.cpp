
/*==============================================================================================================
         __                    __                                             _____     ______    _______
        |  |                  |  |                                           /  __ \   / _____|  / ______|
      __|  |__              __|  |_                                          |_|  | |  | |       | |
     |__|   __|            |__|   __|                                             | |  | |____   | |_____
        |  |    _____         |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
        |  |_  | |_| | | |    |  |_  | |   | \_/ | | |_| | | /  \ | | |_| |    / /___   ____| |  | |___| |
        \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  | | \__   |   |______| |______/  \_______/
                                                                        | |
                                                                      __/ |
                                                                     |___/
                             Nothing is impossible, only you think it is impossible
                                     Try, try, try again until you succeed
                                        Pratice, practice, and practice
                                       Where is your bug, delete it there
I hated every minute of training, but I said, �Don�t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
char matran[105][105];
ll n; 
ll ans[105][105];
ll dx[]={1, -1, 0, 0}, dy[]={0, 0, 1, -1};

bool isvalid(ll x, ll y)
{
  if (x>=1 && x<=n && y>=1 && y<=n  && matran[x][y]!='X') return true;
  return false;
}

void solve()
{
    cin>>n;             
    memset(ans, -1, sizeof(ans));
    for (ll i=1; i<=n; i++)
      for (ll j=1; j<=n; j++) cin>>matran[i][j];

    queue<pair<ll, ll>> q;
    ll a, b, c, d; cin>>a>>b>>c>>d;
    ++a; ++b; ++c; ++d;
    q.push({a, b}); 
    ans[a][b]=0;
    while (!q.empty())
    {
        pair<ll, ll> dinh=q.front(); q.pop();
        ll x=dinh.first, y=dinh.second;

        for (ll i=x-1; i>=1; i--)
        {
          if (isvalid(i, y)==true)
          {
            q.push({i, y});
            ans[i][y]=ans[x][y]+1;
          }
          else break;
        }

        for (ll i=x+1; i<=n; i++)
        {
          if (isvalid(i, y)==true)
          {
            q.push({i, y});
            ans[i][y]=ans[x][y]+1;
          }
          else break;
        }

        for (ll i=y-1; i>=1; i--)
        {
          if (isvalid(x, i)==true)
          {
            q.push({x, i});
            ans[x][i]=ans[x][y]+1;
          }
          else break;
        }

        for (ll i=y+1; i<=n; i++)
        {
          if (isvalid(x, i)==true)
          {
            q.push({x, i});
            ans[x][i]=ans[x][y]+1;
          }
          else break;
        }
    }
    for (ll i=1; i<=n; i++)
    {
      for (ll j=1; j<=n; j++) cout<<ans[i][j]<<" "; cout<<endl;
    }
    cout<<ans[c][d];
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
