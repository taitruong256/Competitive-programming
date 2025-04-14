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
ll dp[100005][25][5], N, K, val[100005];

void solve()
{
    setIO("hps");
    cin>>N>>K;
    for (ll i=1; i<=N; i++)
    {
        char c; cin>>c;
        if (c=='P') val[i]=0;
        else if (c=='H') val[i]=1;
        else val[i]=2;
    }

    ll ans=0;
    for (ll i=1; i<=N; i++)
        for (ll j=0; j<=K; j++)
        {
            for (ll k=0; k<3; k++) dp[i][j][k]=dp[i-1][j][k];
            if (j>0)
            {
                for (ll k=0; k<3; k++) dp[i][j][k]=max({dp[i][j][k], dp[i][j-1][(k+1)%3], dp[i][j-1][(k+2)%3]});
            }
            for (ll k=0; k<3; k++) dp[i][j][k]+=(k==(val[i]+1)%3);
            for (ll k=0; k<3; k++) ans=max(ans, dp[i][j][k]);
        }
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