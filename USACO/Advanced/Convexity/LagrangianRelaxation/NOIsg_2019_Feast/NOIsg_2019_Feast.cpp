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

ll n, k, a[300005];
pair<ll, ll> dp[300005][3];  //sum doan, cnt doan
ll l, r, ans;

bool check(ll m)
{
    dp[0][0]={0, 0};
    dp[0][1]={-1e18, 0};
    for (ll i=1; i<=n; i++)
    {
        dp[i][0]=max(dp[i-1][0], dp[i-1][1]);
        dp[i][1]=max(   make_pair(dp[i-1][1].first+a[i], dp[i-1][1].second),   //them a[i] vao doan truoc do
                        make_pair(dp[i-1][0].first+a[i]-m, dp[i-1][0].second+1));  // bat dau doan moi tai vi tri a[i]
    }
    return max(dp[n][0], dp[n][1]).second>=k;
}

void solve()
{
    cin>>n>>k;
    for (ll i=1; i<=n; i++) cin>>a[i];
    l=0, r=1e15;
    while (l<=r)
    {
        ld mid=(l+r)/2;
        if (check(mid)==true) ans=mid, l=mid+1;
        else r=mid-1;
    }
    check(ans);
    cout<<llround(max(dp[n][0], dp[n][1]).first+ans*k);
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