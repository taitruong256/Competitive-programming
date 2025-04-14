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
const ll maxp = 1LL<<7;
const ll mod = 1e9+7;
ll N, P, K, a[100005], dp[100005][maxp+5], pos[100005], s[100005][10];

ll comp(ll x, ll y)
{
    return a[x]>a[y];
}

void solve()
{
    cin>>N>>P>>K;
    for (ll i=1; i<=N; i++) cin>>a[i], pos[i]=i;
    for (ll i=1; i<=N; i++)
        for (ll j=1; j<=P; j++) cin>>s[i][j];
    sort(pos+1, pos+N+1, comp);
    for (ll i=0; i<=N+1; i++)
        for (ll j=0; j<(1LL<<P); j++) dp[i][j]=-1e18;
    dp[0][0]=0;
    for (ll i=1; i<=N; i++)
    {
        ll x=pos[i];
        for (ll mask=0; mask<(1LL<<P); mask++) 
        {
            for (ll j=0; j<P; j++)
                if (mask&(1LL<<j))
                {
                    ll pre=mask-(1LL<<j);
                    dp[i][mask]=max(dp[i][mask], dp[i-1][pre]+s[x][j+1]);
                }
            ll used=i-1-__builtin_popcount(mask);
            if (used<K) dp[i][mask]=max(dp[i][mask], dp[i-1][mask]+a[x]);
            else dp[i][mask]=max(dp[i][mask], dp[i-1][mask]);
        }
    }
    cout<<dp[N][(1LL<<P)-1];
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