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
const ll mod = 998244353;
ll fact[300005];

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
  ll ans=1;
  ans=(ans*fact[n])%mod;
  ans=(ans*binpow(fact[k], mod-2, mod))%mod;
  ans=(ans*binpow(fact[n-k], mod-2, mod))%mod;
  return ans;
}

void solve()
{
    ll n; cin>>n;
    fact[0]=1;
    for (ll i=1; i<=n; i++) fact[i]=(fact[i-1]*i)%mod;
    ll ans=nCk(n/3, n/6); 
    ll sum=1;
    for (ll i=1; i<=n/3; i++)
    {
      vector<ll> v(3);
      for (ll j=0; j<3; j++) cin>>v[j];
      sort(v.begin(), v.end());
      ll cnt=0;
      for (ll j=0; j<3; j++) cnt+=(v[j]==v[0]);
      sum=(sum*cnt)%mod;  
    }
    ans=(ans*sum)%mod;
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