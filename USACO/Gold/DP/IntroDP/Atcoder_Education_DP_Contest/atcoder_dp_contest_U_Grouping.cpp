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
const ll maxn = 1LL<<16+5;
ll n, a[20][20], cost[maxn], dp[maxn];

void solve()
{
    cin>>n;
    for (ll i=0; i<n; i++)
        for (ll j=0; j<n; j++) cin>>a[i][j];
    for (ll k=0; k<(1LL<<n); k++)
    {
        ll sum=0;
        for (ll i=0; i<n; i++) if (k&(1LL<<i))
            for (ll j=i+1; j<n; j++) if (k&(1LL<<j))
                sum+=a[i][j];
        cost[k]=sum;
    }

    for (ll i=0; i<(1LL<<n); i++)
    {
        ll m=((1LL<<n)-1)^i;
        for (ll j=m; j>0; j=(j-1)&m) 
            dp[i^j]=max(dp[i^j], dp[i]+cost[j]);
    }
    cout<<dp[(1LL<<n)-1];
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