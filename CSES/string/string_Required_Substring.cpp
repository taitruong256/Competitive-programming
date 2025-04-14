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
const ll mod = 1e9+7;
ll dp[1005][105], len[105][26];

ll binpow(ll x, ll n, ll mod)
{
    ll ans=1;
    while (n>0)
    {
        if (n%2==1) ans=(ans*x)%mod;
        x=(x*x)%mod;
        n/=2;
    }
    return ans;
}

void solve()
{
    ll n; cin>>n;
    string s; cin>>s;
    ll m=s.size();
    for (ll i=0; i<m; i++)
    {
        for (ll j=0; j<26; j++)
        {
            string pre=s.substr(0, i);
            pre+=j+'A';
            len[i][j]=0;
            for (ll k=0; k<pre.size(); k++) if (pre.substr(k)==s.substr(0, pre.size()-k))
            {
                len[i][j]=pre.size()-k;
                break;
            }
        }
    }

    dp[0][0]=1;
    for (ll i=1; i<=n; i++)
        for (ll j=0; j<m; j++)
            for (ll k=0; k<26; k++)
                dp[i][len[j][k]]=(dp[i][len[j][k]]+dp[i-1][j])%mod;
            
    ll ans=binpow(26, n, mod);
    for (ll i=0; i<m; i++) ans=(ans-dp[n][i]+mod)%mod;
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