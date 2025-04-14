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
const ll inf = 1e18;
const ll mod = 1e9+7;

void setIO(string s)
{
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}
ll n, m, x, y, dp[1005][1005];
pair<ll, ll> john[1005], bessi[1005];

pair<ll, ll> huong(ll x, ll y, char c)
{
    if (c=='N') return {x, y+1};
    if (c=='S') return {x, y-1};
    if (c=='E') return {x+1, y};
    return {x-1, y};
}

ll sqr(ll x)
{
    return x*x;
}

ll dist(pair<ll, ll> a, pair<ll, ll> b)
{
    return sqr(a.first-b.first)+sqr(a.second-b.second);
}

void solve()
{
    setIO("radio");
    cin>>n>>m;
    cin>>x>>y;
    john[0]={x, y};
    cin>>x>>y;
    bessi[0]={x, y};
    string s; cin>>s;
    for (ll i=1; i<=n; i++) john[i]=huong(john[i-1].first, john[i-1].second, s[i-1]);
    string t; cin>>t;
    for (ll i=1; i<=m; i++) bessi[i]=huong(bessi[i-1].first, bessi[i-1].second, t[i-1]);
    for (ll i=0; i<=n+1; i++)
        for (ll j=0; j<=m+1; j++) dp[i][j]=1e12;

    dp[0][0]=0;
    for (ll i=0; i<n; i++) 
        for (ll j=0; j<m; j++)
        {
            dp[i+1][j]=min(dp[i+1][j], dp[i][j]+dist(john[i+1], bessi[j]));
            dp[i][j+1]=min(dp[i][j+1], dp[i][j]+dist(john[i], bessi[j+1]));
            dp[i+1][j+1]=min(dp[i+1][j+1], dp[i][j]+dist(john[i+1], bessi[j+1]));
        }
    cout<<dp[n][m];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}