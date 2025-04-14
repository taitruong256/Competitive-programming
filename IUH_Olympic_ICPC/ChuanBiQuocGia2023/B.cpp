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
                                Hãy hoàn thành công việc một cách cẩu thả nhất
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
char c[105][105];
ll x=-1, y=-1, n;
ll dx[]={0, 0, -1, 1};
ll dy[]={1, -1, 0, 0};

ll run(ll huong, ll x, ll y)
{
    ll cnt=0;
    while (x>=1 && x<=n && y>=1 && y<=n && (c[x][y]=='M' || c[x][y]=='O'))
    {
        x+=dx[huong];
        y+=dy[huong];
        cnt+=1;
    }
    if (x<1 || x>n || y<1 || y>n) return cnt;
    return 1e18;
}

void solve()
{
    cin>>n;
    for (ll i=0; i<=n+1; i++)
        for (ll j=0; j<=n+1; j++)
            c[i][j]='O';
    for (ll i=1; i<=n; i++) 
        for (ll j=1; j<=n; j++)
        {
            cin>>c[i][j];
            if (c[i][j]=='M') x=i, y=j;
        }
    ll h1=run(0, x, y);
    ll h2=run(1, x, y);
    ll h3=run(2, x, y);
    ll h4=run(3, x, y);
    ll ans=min({h1, h2, h3, h4});
    if (ans==1e18) ans=-1;
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