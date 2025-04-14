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
Cai tien tu phien ban de cua bai.
Nhận xét thấy chỉ cần tìm đường đi dài nhất nên có thể loại bỏ chiều j, ta sẽ dùng một mảng cnt để lưu chiều dài lớn nhất kết thúc 
tại vị trí i.

*/

ll nCk[5005][5005];

void solve()
{
    ll n, k; cin>>n>>k;
    vector<ll> col(n+5), cnt(n+5), dp(n+5);
    for (ll i=1; i<=n; i++) cin>>col[i];
    dp[0]=1;
    ll mx=0;
    for (ll i=1; i<=n; i++)
    {
        ll val=0;
        for (ll j=i; j>=1; j--) 
        {
            if (col[i]==col[j]) ++val;
            if (val>=k) 
            {
                if (cnt[i]<cnt[j-1]+1) cnt[i]=cnt[j-1]+1, dp[i]=dp[j-1]*nCk[val-1][k-1], dp[i]%=mod;
                else if (cnt[i]==cnt[j-1]+1) dp[i]+=dp[j-1]*nCk[val-1][k-1], dp[i]%=mod;
            }
        }
        mx=max(mx, cnt[i]);
        // cout<<i<<"   "<<endl;
        // for (ll j=0; j<=n; j++) cout<<cnt[j]<<" "; cout<<endl;
        // for (ll j=0; j<=n; j++) cout<<dp[j]<<" "; cout<<endl<<endl;
    }
    ll ans=0;
    for (ll i=0; i<=n; i++) if (cnt[i]==mx) ans=(ans+dp[i])%mod;
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

    nCk[0][0]=1;
    for (ll i=1; i<=5000; i++)
    {   
        nCk[i][0]=1;
        for (ll j=1; j<=i; j++) nCk[i][j]=(nCk[i-1][j-1]+nCk[i-1][j])%mod;
    }

    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}