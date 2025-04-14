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
ll w, h, n, fact[200005], dp[200005];

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
    return fact[n]*binpow(fact[k], mod-2, mod)%mod*binpow(fact[n-k], mod-2, mod)%mod;
}

void solve()
{
    fact[0]=1;
    for (ll i=1; i<=200000; i++) fact[i]=(fact[i-1]*i)%mod;
    cin>>h>>w>>n;
    pair<ll, ll> p[n+5];
    for (ll i=1; i<=n; i++) cin>>p[i].first>>p[i].second;
    p[n+1]={h, w};
    sort(p+1, p+n+1+1);
    for (ll i=1; i<=n+1; i++)
    {    
        auto [x, y]=p[i];          
        dp[i]=nCk(x-1+y-1, x-1);           
        for (ll j=1; j<i; j++) 
        {
            auto [xx, yy]=p[j];
            dp[i]=(dp[i]-dp[j]*nCk(x-xx+y-yy, x-xx)+mod*mod)%mod;
        }
    }
    cout<<dp[n+1]<<endl;
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