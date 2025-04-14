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

void solve()
{
    ll n, s; cin>>n>>s;
    ll a[n+5], x[n+5], y[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
   
    for (ll i=2; i<=n-1; i++)
    {
        if (a[i]<=s) 
        {
            x[i]=0;
            y[i]=a[i];
        }
        else if (a[i]<=s*2) 
        {
            x[i]=a[i]-s;
            y[i]=s;
        }
        else 
        {
            x[i]=s;
            y[i]=a[i]-s;
        }
    }

    ll dp[n+5][3];
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=2; j++) dp[i][j]=1e18;
    for (ll i=2; i<=n-1; i++)
    {
        if (i==2)
        {
            dp[i][0]=a[1]*x[2];
            dp[i][1]=a[1]*y[2];
        }   
        else 
        {
            dp[i][0]=min(dp[i-1][0]+y[i-1]*x[i], dp[i-1][1]+x[i-1]*x[i]);
            dp[i][1]=min(dp[i-1][0]+y[i-1]*y[i], dp[i-1][1]+x[i-1]*y[i]);
        }
    }
    cout<<min(dp[n-1][0]+y[n-1]*a[n], dp[n-1][1]+x[n-1]*a[n])<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}