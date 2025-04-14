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
const ll maxn = 1LL<<20;
const ll mod = 1e9+7;

void setIO(string s)
{
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}

ll dp[maxn+5], N, H, height[maxn+5], h[25], w[25], s[25];

void solve()
{
    setIO("guard");
    cin>>N>>H;
    for (ll i=0; i<N; i++) cin>>h[i]>>w[i]>>s[i];
    dp[0]=1e18;
    ll ans=-1;
    for (ll i=1; i<(1LL<<N); i++)
    {
        dp[i]=-1;
        for (ll j=0; j<N; j++) if (i&(1LL<<j))
        {
            height[i]+=h[j];
            if (dp[i^(1LL<<j)]>=w[j]) dp[i]=max(dp[i], min(dp[i^(1LL<<j)]-w[j], s[j]));
        }
        if (height[i]>=H) ans=max(ans, dp[i]);
    }
    if (ans==-1) cout<<"Mark is too tall\n";
    else cout<<ans;
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