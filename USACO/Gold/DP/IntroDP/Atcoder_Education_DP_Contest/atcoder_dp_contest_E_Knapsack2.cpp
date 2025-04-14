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
ll dp[105][100005], weight[105], value[105];
ll N, W;

void solve()
{
    for (ll i=0; i<=100; i++)
      for (ll j=0; j<=100000; j++) dp[i][j]=1e18;
    cin>>N>>W;
    for (ll i=0; i<=N; i++) dp[i][0]=0;
    for (ll i=1; i<=N; i++) cin>>weight[i]>>value[i];
    for (ll i=1; i<=N; i++)
    {
        for (ll j=1; j<=100000; j++) 
        {
            dp[i][j]=dp[i-1][j];
            if (j>=value[i]) dp[i][j]=min(dp[i-1][j], dp[i-1][j-value[i]]+weight[i]);
        }
    }
    for (ll i=100000; i>=0; i--) if (dp[N][i]<=W)
    {
        cout<<i;
        return;
    }
    cout<<0;
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