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
                             Nothing is impossible, only you think it is impossible                 
                                     Try, try, try again until you succeed     
                                        Pratice, practice, and practice
                                       Where is your bug, delete it there
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;

void solve()
{
  ll n; cin>>n;
  ll a[n+5];
  for (ll i=1; i<=n; i++) cin>>a[i];
  ll pos0=-1, pos1=-1;
  for (ll i=1; i<=n; i++) if (a[i]==0)
  {
    pos0=i;
    break;
  }
  for (ll i=n; i>=1; i--) if (a[i]==1) 
  {
    pos1=i;
    break;
  }
  ll ans1=0, cnt=0;
  for (ll i=1; i<=n; i++)
    if (a[i]==1) ++cnt;
    else ans1+=cnt;

  ll ans2=0; cnt=0;
  if (pos0!=-1) a[pos0]=1;
  for (ll i=1; i<=n; i++) 
    if (a[i]==1) ++cnt;
    else ans2+=cnt;
  if (pos0!=-1) a[pos0]=0;

  ll ans3=0; cnt=0;
  if (pos1!=-1) a[pos1]=0;
  for (ll i=1; i<=n; i++) 
    if (a[i]==1) ++cnt;
    else ans3+=cnt;
  cout<<max({ans1, ans2, ans3})<<endl;
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