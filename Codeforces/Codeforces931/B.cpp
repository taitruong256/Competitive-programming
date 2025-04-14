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
                                       Where is the bug, delete it there
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

void solve()
{
    ll n; cin>>n;
    vector<ll> dp(3005, 1e18);
    vector<ll> coin={1, 3, 6, 10, 15};
    dp[0]=0;
    for (ll i=1; i<=3000; i++) 
        for (ll j: coin)   
            if (i>=j) 
                dp[i]=min(dp[i], dp[i-j]+1);
    ll ans=n/3000*200+dp[n%3000];

    ll f[105][105];
    for (ll i=0; i<=n; i++) 
        for (ll j=0; j<=n; j++) f[i][j]=1e18;
    for (ll i=0; i<=100; i++) f[i][0]=0;
    for (ll i=0; i<sz(coin); i++)
    {
        for (ll j=1; j<=n; j++)
        {
            f[i][j]=f[i-1][j];
            if (j>=coin[i]) f[i][j]=min(f[i][j], f[i][j-coin[i]]+1);
        }
    }
    for (ll i=0; i<coin.size(); i++)
    {
        for (ll j=1; j<=n; j++) cout<<f[i][j]<<" ";
        cout<<endl;
    }
    if (ans!=f[4][n]) cerr<<n<<" "<<ans<<" "<<f[4][n]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}