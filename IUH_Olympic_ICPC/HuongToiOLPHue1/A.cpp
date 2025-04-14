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
                                       Where is the bug, delete it there
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
ll n, m, d[105][105], sum[105][105];
ll dx[]={0, 0, -1, 1};
ll dy[]={-1, 1, 0, 0};
bool cam[105][105], bi[105][105];
pair<ll, ll> p[105];
bool lienthong=1;

void bfs(pair<ll, ll> nguon)
{
    for (ll i=0; i<=101; i++)
        for (ll j=0; j<=101; j++) d[i][j]=-1;

    queue<pair<ll, ll>> q;
    q.push(nguon);
    d[nguon.first][nguon.second]=0;
    ll cnt=0;
    while(!q.empty())
    {
        auto [x, y]=q.front(); q.pop();
        if (bi[x][y]==1) cnt+=1;
        for (ll i=0; i<4; i++)
        {
            ll newx=x+dx[i], newy=y+dy[i];
            if (0<=newx && newx<=101 && 0<=newy && newy<=101 && d[newx][newy]==-1 && cam[newx][newy]==0)
            {
                q.push({newx, newy});
                d[newx][newy]=d[x][y]+1;
                sum[newx][newy]+=d[newx][newy];
            }
        }
    }
    if (cnt<m) lienthong=0;
}

ll dist(pair<ll, ll> a, pair<ll, ll> b)
{
    return abs(a.first-b.first)+abs(a.second-b.second);
}

void solve()
{
    cin>>n; //assert(n!=0);
    for (ll i=1; i<=n; i++)
    {
        ll x, y; cin>>x>>y;  
        cam[x][y]=1;
    }
    cin>>m;
    for (ll i=1; i<=m; i++) 
    {
        ll x, y; cin>>x>>y;
        bi[x][y]=1;
        p[i]={x, y};
    }


    if (n==0)
    {
    }
    else 
    {
        ll ans=1e18;
        for (ll i=1; i<=m; i++) bfs(p[i]);
        for (ll i=0; i<=101; i++)
            for (ll j=0; j<=101; j++) 
                if (cam[i][j]==0)
                    ans=min(ans, sum[i][j]);
        if (ans==1e18) ans=-1;
        cout<<ans;
    }
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