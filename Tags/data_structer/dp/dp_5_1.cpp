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
ll n, a[505], dp[505][505];

void solve()
{
    cin>>n;
    for (ll i=1; i<=n+1; i++) cin>>a[i];

    for (ll i=0; i<=n+1; i++)
        for (ll j=0; j<=n+1; j++) dp[i][j]=1e9;
    for (ll i=1; i<=n; i++) dp[i][i]=0;
    for (ll i=1; i<=n-1; i++) dp[i][i+1]=a[i]*a[i+1]*a[i+2];

    for (ll m=2; m<=n-1; m++)
        for (ll i=1; i<=n-m; i++)
        {
            ll j=i+m, mn=1e9;
            for (ll k=i; k<=j-1; k++) 
                mn=min(mn, dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);
            dp[i][j]=mn;
        }
    cout<<dp[1][n];
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