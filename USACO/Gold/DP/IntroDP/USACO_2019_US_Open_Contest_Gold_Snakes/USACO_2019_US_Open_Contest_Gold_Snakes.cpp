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
ll N, K, dp[405][405], a[405];
//dp[i][j]: co i con ran dau tien va j lan chuyen doi 

void solve()
{
    setIO("snakes");
    cin>>N>>K;
    for (ll i=1; i<=N; i++) cin>>a[i];
    ll max_group=0, sum=0;
    for (ll i=1; i<=N; i++)
    {
        max_group=max(max_group, a[i]);
        sum+=a[i];
        dp[i][0]=max_group*i;
        for (ll j=1; j<=K; j++) 
        {
            dp[i][j]=1e18;
            ll mx=a[i];
            for (ll k=i-1; k>=0; k--)
            {
                dp[i][j]=min(dp[i][j], dp[k][j-1]+mx*(i-k));
                mx=max(mx, a[k]);
            }
        }
    }
    cout<<dp[N][K]-sum;
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