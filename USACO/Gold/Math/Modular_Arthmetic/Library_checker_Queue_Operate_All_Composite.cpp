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
const ll mod = 998244353;

ll binpow(ll x, ll n)
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
  ll query; cin>>query;
  queue<pair<ll, ll>> q;
  ll A=1, B=0;
  while (query--)
  {
    ll type; cin>>type; 
    if (type==0)
    {
      ll a, b; cin>>a>>b;
      q.push({a, b});
      A=(A*a)%mod;
      B=(a*B+b)%mod;
    }
    else if (type==1)
    {
      auto [a, b]=q.front();
      q.pop();
      A=(A*binpow(a, mod-2))%mod;
      B=(B-A*b+mod*mod)%mod;
    }
    else 
    {
      ll x; cin>>x;
      cout<<(A*x+B)%mod<<endl;
    }
  }
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