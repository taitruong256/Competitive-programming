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
#define ll int
#define endl '\n'
const ll mod = 1e9+7;
ll n, a[5005], dp[5005][5005], mn[5005][5005], mx[5005][5005];

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=0; i<=n+1; i++)
        for (ll j=0; j<=n+1; j++) dp[i][j]=mn[i][j]=1e9, mx[i][j]=0;
    for (ll i=1; i<=n; i++) 
    {
        dp[i][i]=0;
        mn[i][i]=a[i];
        mx[i][i]=a[i];
        if (i+1<=n) dp[i][i+1]=(a[i]>a[i+1]);
        if (i+1<=n) mn[i][i+1]=min(a[i], a[i+1]);
        if (i+1<=n) mx[i][i+1]=max(a[i], a[i+1]);
    }
    for (ll len=3; len<=n; len++)
    {
        for (ll i=1; i+len-1<=n; i++)
        {
            ll j=i+len-1;
            mn[i][j]=min(mn[i][j-1], a[j]);
            mx[i][j]=max(mx[i][j-1], a[j]);
            if (a[i]==mn[i][j] && a[j]==mx[i][j]) dp[i][j]=min(dp[i][j], dp[i+1][j-1]);
            else if (a[i]==mn[i][j]) dp[i][j]=min(dp[i][j], dp[i+1][j]);
            else if (a[j]==mx[i][j]) dp[i][j]=min(dp[i][j], dp[i][j-1]);
            else dp[i][j]=min(dp[i][j], j-i);
            // cout<<i<<" "<<j<<" "<<mn[i][j]<<" "<<mx[i][j]<<endl;
        }
    }
    // for (ll i=1; i<=n; i++)
    // {
    //     for (ll j=1; j<=n; j++) 
    //         if (mn[i][j]==1e9) cout<<"inf "; 
    //         else cout<<mn[i][j]<<" "; 
    //     cout<<endl;
    // }
    // for (ll i=1; i<=n; i++)
    // {
    //     for (ll j=1; j<=n; j++) 
    //         if (mx[i][j]==1e9) cout<<"inf "; 
    //         else cout<<mx[i][j]<<" "; 
    //     cout<<endl;
    // }
    // for (ll i=1; i<=n; i++)
    // {
    //     for (ll j=1; j<=n; j++) 
    //         if (dp[i][j]==1e9) cout<<"inf "; 
    //         else cout<<dp[i][j]<<" "; 
    //     cout<<endl;
    // }
    ll ans=0;
    for (ll i=1; i<=n; i++)
        for (ll j=i; j<=n; j++) ans+=dp[i][j];
    cout<<ans<<endl;
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