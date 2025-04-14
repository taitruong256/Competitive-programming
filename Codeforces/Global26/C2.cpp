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
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
     Laziness is only temporary comfort. The future will regret that day. Don't fall into the trap of comfort.
                The most beautiful meeting in this world is meeting the best version of yourself.
                          Practice doing things you don't like but are useful to you
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 998244353;

ll dp[300005][4], cnt[300005][4];

void solve()
{
    ll n; cin>>n;
    ll a[n+5], sum=0;
    for (ll i=1; i<=n; i++) cin>>a[i];
    
    cnt[1][1]=cnt[1][2]=cnt[1][3]=(a[1]>=0)+1;
    dp[1][1]=dp[1][3]=abs(a[1]);
    dp[1][2]=a[1];

    for (ll i=2; i<=n; i++)
    {
        cnt[i][1]=cnt[i][2]=cnt[i][3]=0;
        ll mx1=max(dp[i-1][1], dp[i-1][3])+a[i];
        ll mn2=min(dp[i-1][2], dp[i-1][3])+a[i];
        ll mx3=max({abs(dp[i-1][1]+a[i]), abs(dp[i-1][2]+a[i]), abs(dp[i-1][3]+a[i])});

        if (dp[i-1][3]+a[i]==mx1) cnt[i][1]+=cnt[i-1][3]*((mx1>=0)+1), cnt[i][1]%=mod;
        if (dp[i-1][1]+a[i]==mx1 && dp[i-1][1]!=dp[i-1][3]) cnt[i][1]+=cnt[i-1][1]*((mx1>=0)+1), cnt[i][1]%=mod;
        
        if (dp[i-1][3]+a[i]==mn2) cnt[i][2]+=cnt[i-1][3]*((mn2>=0)+1), cnt[i][2]%=mod;
        if (dp[i-1][2]+a[i]==mn2 && dp[i-1][2]!=dp[i-1][3]) cnt[i][2]+=cnt[i-1][2]*((mn2>=0)+1), cnt[i][2]%=mod;
        
        bool check=false;
        if (abs(dp[i-1][3]+a[i])==mx3) cnt[i][3]+=cnt[i-1][3]*(((dp[i-1][3]+a[i])>=0)+1), check=true;
        if (abs(dp[i-1][1]+a[i])==mx3 && check==false) cnt[i][3]+=cnt[i-1][1]*(((dp[i-1][1]+a[i])>=0)+1), check=true;
        if (abs(dp[i-1][2]+a[i])==mx3 && check==false) cnt[i][3]+=cnt[i-1][2]*(((dp[i-1][2]+a[i])>=0)+1), check=true;
        

        dp[i][1]=mx1;
        dp[i][2]=mn2;
        dp[i][3]=mx3;
    }

    for (ll j=1; j<=3; j++)
    {
        for (ll i=1; i<=n; i++) cout<<dp[i][j]<<" "; 
        cout<<endl;
    }

    cout<<endl;
    for (ll j=1; j<=3; j++)
    {
        for (ll i=1; i<=n; i++) cout<<cnt[i][j]<<" "; 
        cout<<endl;
    }

    ll mx=max({dp[n][1], dp[n][2], dp[n][3]}), ans=0;
    if (dp[n][1]==mx) ans=(ans+cnt[n][1])%mod;
    if (dp[n][2]==mx) ans=(ans+cnt[n][2])%mod;
    if (dp[n][3]==mx) ans=(ans+cnt[n][3])%mod;
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

    cnt[0][1]=cnt[0][2]=cnt[0][3]=1;

    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}