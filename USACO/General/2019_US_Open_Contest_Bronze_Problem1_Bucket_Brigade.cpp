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
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
char a[15][15];
ll dx[]={0, 0, 1, -1};
ll dy[]={1, -1, 0, 0};
ll d[15][15];
ll xf, yf;

ll bfs(ll x, ll y)
{
    queue<pair<ll, ll>> q;
    q.push({x, y});
    while (!q.empty())
    {
        auto [u, v]=q.front(); q.pop();  // cout<<u<<" "<<v<<endl;
        if (u==xf && v==yf) return d[u][v];
        for (ll i=0; i<4; i++)
        {
            ll new_x=u+dx[i];
            ll new_y=v+dy[i];
            if (1<=new_x<=10 && 1<=new_y<=10 && (a[new_x][new_y]=='.' || a[new_x][new_y]=='B')) 
            {
                d[new_x][new_y]=d[u][v]+1;
                q.push({new_x, new_y});
                a[new_x][new_y]='#';
            }
        }
    }
    return -1;
}

void solve()
{
    ll x=1, y=1;
    for (ll i=1; i<=10; i++)
        for (ll j=1; j<=10; j++) 
        {
            cin>>a[i][j];
            if (a[i][j]=='L') x=i, y=j;
            if (a[i][j]=='B') xf=i, yf=j;
        }
    cout<<bfs(x, y)-1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}