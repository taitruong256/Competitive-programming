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
                             Nothing is impossible, only you think it is impossible                 
                                     Try, try, try again until you succeed     
                                        Pratice, practice, and practice
                                       Where is your bug, delete it there
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
ll dp[1005][105];
ll t, s, c, k, l, d; 

void solve()
{
    cin>>t>>s>>c>>k>>l>>d;  
    for (ll i=0; i<=t; i++)
        for (ll j=0; j<=c; j++) dp[i][j]=-inf;

    dp[0][c]=0;
    if (d>=c)
        for (ll i=1; i<=c; i++) dp[0][i]=0;
    for (ll i=1; i<=t; i++)
    {
        for (ll j=0; j<=c; j++) 
        {
            ll mx=-inf;
            if (j+l<=c) mx=max(mx, dp[i-1][j+l]+1);
            if (j+k<=c) mx=max(mx, dp[i-1][j+k]);
            if (j-d>=0) mx=max(mx, dp[i-1][j-d]-1);
            dp[i][j]=mx;
            dp[i+1][min(j+d, c)]=max({mx, dp[i+1][min(j+d, c)], 0LL});  
        }
    }

    // for (ll i=1; i<=t; i++)
    // {
    //     for (ll j=0; j<=c; j++) 
    //     {
    //         ll mx=-inf;
    //         if (j+l<=c) mx=max(mx, dp[i-1][j+l]);
    //         if (j+k<=c) mx=max(mx, dp[i-1][j+k]);
    //         if (j-d>=0) mx=max(mx, dp[i-1][j-d]);
    //         dp[i][j]+=mx;
    //     }
    // }

    for (ll i=0; i<=t; i++)
    {
        for (ll j=0; j<=c; j++) cout<<dp[i][j]<<" ";
        cout<<endl;
    }

    ll ans=0;
    for (ll i=0; i<=c; i++) ans=max(ans, dp[t][i]);
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