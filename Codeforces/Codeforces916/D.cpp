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

vector<ll> a[100005];

bool comp1(const vector<ll> &x, const vector<ll> &y)
{
  if (x[0]==y[0]) x[1]<y[1];
  return x[0]>y[0];
}

bool comp2(const vector<ll> &x, const vector<ll> &y)
{
  return x[1]>y[1];
}

bool comp3(const vector<ll> &x, const vector<ll> &y)
{
  return x[2]>y[2];
}

void solve()
{
  ll n; cin>>n;
  for (ll i=1; i<=n; i++) 
  {
    ll x; cin>>x;
    a[i].push_back(x);
  }
  for (ll i=1; i<=n; i++) 
  {
    ll x; cin>>x;
    a[i].push_back(x);
  }
  for (ll i=1; i<=n; i++) 
  {
    ll x; cin>>x;
    a[i].push_back(x);
  }
  ll ans=0;
  sort(a+1, a+n+1, comp1);
  sort(a+2, a+n+1, comp2);
  sort(a+3, a+n+1, comp3);
  ans=max(ans, a[1][0]+a[2][1]+a[3][2]);
  sort(a+1, a+n+1, comp1);
  sort(a+2, a+n+1, comp3);
  sort(a+3, a+n+1, comp2);
  ans=max(ans, a[1][0]+a[2][2]+a[3][1]);
  sort(a+1, a+n+1, comp2);
  sort(a+2, a+n+1, comp1);
  sort(a+3, a+n+1, comp3);
  ans=max(ans, a[1][1]+a[2][0]+a[3][2]);
  sort(a+1, a+n+1, comp2);
  sort(a+2, a+n+1, comp3);
  sort(a+3, a+n+1, comp1);
  ans=max(ans, a[1][1]+a[2][2]+a[3][0]);
  sort(a+1, a+n+1, comp3);
  sort(a+2, a+n+1, comp1);
  sort(a+3, a+n+1, comp2);
  ans=max(ans, a[1][2]+a[2][0]+a[3][1]);
  sort(a+1, a+n+1, comp3);
  sort(a+2, a+n+1, comp2);
  sort(a+3, a+n+1, comp1);
  ans=max(ans, a[1][2]+a[2][1]+a[3][0]);
  cout<<ans<<endl;
  for (ll i=1; i<=n; i++) a[i].clear();
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  clock_t start = clock();
  #ifndef ONLINE_JUDGE
  freopen("_input.txt", "r", stdin);
  freopen("_output.txt", "w", stdout);
  #endif
  ll t; cin>>t;
  while (t--) solve();
  clock_t end = clock();
  cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
  return 0;
}