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
ll n, a[1005], dp[1005][1005][2];

void solve()
{
    setIO("cowrun");
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);
    for (ll i=0; i<=n; i++)
        for (ll j=0; j<=n; j++) 
            if (i!=j) dp[i][j][0]=dp[i][j][1]=1e18;
            else dp[i][j][0]=dp[i][j][1]=abs(a[i])*n;
    
    for (ll i=n-1; i>=1; i--)
    {
        for (ll j=i+1; j<=n; j++)
        {
            ll remain=n-j+i;
            dp[i][j][0]=min(dp[i+1][j][0]+abs(a[i+1]-a[i])*remain, dp[i+1][j][1]+abs(a[j]-a[i])*remain);
            dp[i][j][1]=min(dp[i][j-1][0]+abs(a[j]-a[i])*remain, dp[i][j-1][1]+abs(a[j]-a[j-1])*remain);
        }
    }
    cout<<min(dp[1][n][0], dp[1][n][1]);
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