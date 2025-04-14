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
    ll n; cin>>n;
    ll a[n+5];
    bool check=false;
    for (ll i=1; i<=n; i++) 
    {
        cin>>a[i];
        if (a[i]==0) check=true;
    }
    if (check==true)
    {
        ll ans=0;
        for (ll i=1; i<=n; i++) ans+=abs(a[i]);
        cout<<ans<<endl;
        return;
    }
    ll dp[n+5][3];
    dp[0][1]=dp[0][2]=0;
    dp[1][1]=a[1];
    dp[1][2]=-a[1];
    for (ll i=2; i<=n; i++) 
    {
        if (i==2)
        {
            dp[i][1]=a[1]+a[2];
            dp[i][2]=-a[1]-a[2];
            continue;
        }
        dp[i][1]=max(dp[i-2][1]+a[i-1]+a[i], dp[i-2][2]-a[i-1]+a[i]);
        dp[i][2]=max(dp[i-2][1]-a[i-1]-a[i], dp[i-2][2]+a[i-1]-a[i]);
    }
    cout<<max(dp[n][1], dp[n][2])<<endl;
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