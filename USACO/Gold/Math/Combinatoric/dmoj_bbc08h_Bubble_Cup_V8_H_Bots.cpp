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
ll dp[2000005], frac[2000005];

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

ll nCk(ll n, ll k)
{
    if (k>n) return 0;
    ll res=frac[n];
    res=(res*binpow(frac[k], mod-2, mod))%mod;
    res=(res*binpow(frac[n-k], mod-2, mod))%mod;
    return res;
}

void solve()
{
    ll n; cin>>n;
    frac[0]=1;
    for (ll i=1; i<=2*n; i++) frac[i]=(frac[i-1]*i)%mod;
    dp[0]=1;
    for (ll i=1; i<=n; i++) dp[i]=(dp[i-1]*2)%mod;
    for (ll i=n+1; i<=2*n-1; i++) dp[i]=(2*dp[i-1]-2*nCk(i-1, n)+mod*mod)%mod;
    dp[2*n]=dp[2*n-1];
    ll ans=0;
    for (ll i=0; i<=2*n; i++) ans=(ans+dp[i])%mod;
    cout<<ans<<endl;
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