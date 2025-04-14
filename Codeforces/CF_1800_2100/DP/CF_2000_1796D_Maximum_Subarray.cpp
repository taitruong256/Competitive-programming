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
const ll mod = 1e9+7;

/*
Cho mảng a có n phần tử, cần cộng x vào chính xác k vị trí khác nhau, trừ x cho các vị trí còn lại.
Gọi a' là mảng sau khi thực hiện. f(a') là mảng con liên tiếp có tổng lớn nhất.
Tìm f(a') lớn nhất.

Input
4
4 1 2
2 -1 2 3
2 2 3
-1 2
3 0 5
3 2 4
6 2 -8
4 -1 9 -3 7 -8
Output
5
7
0
44

Ý tưởng:
Gọi dp[i][j]: giá trị lớn nhất của đoạn con liên tiếp thực hiện j phép cộng.
    -Không cộng a[i]: dp[i][j]=min(dp[i][j], dp[i-1][j]+a[i]-x)
    -Cộng a[i]: dp[i][j]=min(dp[i][j], dp[i-1][j-1]+a[i]+x) với (j>=1)
*/

ll n, k, x, a[200005], dp[200005][25];

void solve()
{
    cin>>n>>k>>x;
    for (ll i=1; i<=n; i++) cin>>a[i];

    for (ll i=0; i<=n; i++)
        for (ll j=0; j<=k; j++)
            dp[i][j]=-1e18;

    dp[0][0]=0;
    for (ll i=1; i<=n; i++)
    {
        for (ll j=0; j<=min(i, k); j++) dp[i][j]=0;
        for (ll j=0; j<=min(i, k); j++)
        {
            dp[i][j]=max(dp[i][j], dp[i-1][j]+a[i]-x);
            if (j>0) dp[i][j]=max(dp[i][j], dp[i-1][j-1]+a[i]+x);
        }
    }

    // for (ll i=1; i<=n; i++)
    // {
    //     for (ll j=0; j<=k; j++) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }            
    // cout<<endl;

    ll ans=0;
    for (ll i=1; i<=n; i++)
        for (ll j=0; j<=k; j++)
            if (i+k-j<=n) ans=max(ans, dp[i][j]);      //đủ k phép cộng, nếu thiếu thì lúc sau sẽ lớn hơn (vì còn k-j lần +x)
    cout<<ans<<endl;
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