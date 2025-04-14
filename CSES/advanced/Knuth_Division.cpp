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
ll n, a[5005], pref[5005], dp[5005][5005], opt[5005][5005];

ll cost(ll l, ll r)
{
    return pref[r]-pref[l-1];
}

void knuth()
{
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) dp[i][j]=inf;
    for (ll i=1; i<=n; i++) 
    {
        dp[i][i]=0;
        opt[i][i]=i;
    }

    for (ll i=n; i>=1; i--)
        for (ll j=i+1; j<=n; j++) 
            for (ll k=opt[i][j-1]; k<=opt[i+1][j]; k++)
                if (dp[i][k]+dp[k+1][j]+cost(i, j)<=dp[i][j])
                {
                    dp[i][j]=dp[i][k]+dp[k+1][j]+cost(i, j);
                    opt[i][j]=k;
                }
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) 
    {
        cin>>a[i];
        pref[i]=pref[i-1]+a[i];
    }
    knuth();
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