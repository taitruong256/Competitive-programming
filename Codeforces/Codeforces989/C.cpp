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

ll n, m, dx[]={0, 0, 1, -1}, dy[]={1, -1, 0, 0};
char c[1005][1005];
ll ans[1005][1005];

ll calc(ll x, ll y)
{
    // cerr<<x<<" "<<y<<endl;
    if (x<1 || x>n || y<1 || y>m) return 0;
    if (ans[x][y]!=-1) return ans[x][y];
    ans[x][y]=1;
    if (c[x][y]=='L') return ans[x][y]=calc(x, y-1);
    else if (c[x][y]=='R') return ans[x][y]=calc(x, y+1);
    else if (c[x][y]=='U') return ans[x][y]=calc(x-1, y);
    else if (c[x][y]=='D') return ans[x][y]=calc(x+1, y);
    else 
    {
        for (ll i=0; i<4; i++)
        {
            ll newx=x+dx[i], newy=y+dy[i];
            if (calc(newx, newy)==1) return ans[x][y]=1;
            // cerr<<res<<endl;
        }
        return ans[x][y]=0;
    }
    return 1;
}

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++)
            cin>>c[i][j], ans[i][j]=-1;

    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++)
            if (ans[i][j]==-1)
                calc(i, j);
    
    ll cnt=0;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++)
            cnt+=ans[i][j];
    cout<<cnt<<endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}