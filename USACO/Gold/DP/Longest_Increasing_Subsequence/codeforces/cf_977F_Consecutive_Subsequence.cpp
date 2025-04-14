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
const ll maxn = 200005;
const ll mod = 1e9+7;

void solve()
{
  ll n; cin>>n;
  ll a[n+5];
  for (ll i=1; i<=n; i++) cin>>a[i];
  map<ll, ll> dp;
  ll ans=0, lst=-1;
  for (ll i=1; i<=n; i++)
  {
    ll x=a[i];
    dp[x]=dp[x-1]+1;
    if (dp[x]>ans)
    {
      ans=dp[x];
      lst=x;
    }
  }
  vector<ll> id;
  for (ll i=n; i>=1; i--)
  {
    if (a[i]==lst) --lst, id.push_back(i);
  }
  reverse(id.begin(), id.end());
  cout<<id.size()<<endl;
  for (auto i: id) cout<<i<<" ";
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