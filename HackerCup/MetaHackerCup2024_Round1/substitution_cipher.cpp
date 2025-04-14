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
                                   Success is born from problem solving
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 998244353;

string s;
ll k, n, cnt=0, now=0, dp[100005];

void solve()
{
    cin>>s; s=" "+s+" ";
    cin>>k; k-=1;
    n=s.size()-2;
    cnt=0;
    now=0;
    for (ll i=1; i<=n; i++) if (s[i]=='?') ++cnt;
    for (ll i=1; i<=n; i++) if (s[i]=='?') 
    {
        ++now;
        if (k>=(1LL<<(cnt-now))) 
        {
            s[i]='1';
            k-=(1LL<<(cnt-now));  
        }
        else s[i]='2';
    }
    for (ll i=1; i<=n; i++) cout<<s[i]; cout<<" ";
    dp[n]=1;
    dp[n+1]=1;
    for (ll i=n-1; i>=1; i--)
    {
        dp[i]=dp[i+1];
        if (s[i]=='1' || s[i]=='2') dp[i]=dp[i+1]+dp[i+2];
        else dp[i]=dp[i+1];
    }
    cout<<dp[1]<<endl;

    for (ll i=1; i<=n; i++) cout<<dp[i]<<" "; cout<<endl;
    for (ll i=0; i<=n+1; i++) dp[i]=0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("substitution_cipher_input.txt", "r", stdin);
    freopen("substitution_cipher_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}