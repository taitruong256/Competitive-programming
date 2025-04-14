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
#define ll unsigned long long
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e19;
const int maxn = 2.5e6;
int divprime[maxn+5];
ll n;
vector<int> nt;
vector<pair<ll, int>> ans;
 
ll luythua(int x, int n)
{
  ll res=1;
  for (int i=1; i<=n; i++)
  {
    if (res>inf/(1ULL*x)) return -1;
    res=res*(1ULL*x);
  }
  return res;
}
 
bool chinhphuong(ll n)
{
  ll d=sqrt(n);
  return 1ULL*d*d==n;
}
 
bool nguyento(ll n)
{
  for (auto i: nt) 
  {
    if (1ULL*i*i>n) return true;
    if (n%i==0) return false;
  }
  return false;
}
 
void solve()
{
  ll n; cin>>n;
  if (chinhphuong(n)==true && nguyento(sqrt(n))==true) 
  {
    ll ans=sqrt(n);
    cout<<ans<<endl;
    return;
  }
  else 
  {
    int pos=lower_bound(ans.begin(), ans.end(), make_pair(n, 0))-ans.begin();
    if (pos!=ans.size() && ans[pos].first==n) cout<<ans[pos].second<<endl;
    else cout<<-1<<endl;
  }
}
 
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  freopen("divpow.inp", "r", stdin);
  freopen("divpow.out", "w", stdout);
  for (int i=1; i<=maxn; i++) 
    for (int j=i; j<=maxn; j+=i) divprime[j]++;
  for (int i=1; i<=maxn; i++) if (divprime[i]==2) nt.push_back(i);
 
  for (int i=1; i<=maxn; i++) 
  {
    ll t=luythua(i, divprime[i]);
    if (t!=-1) ans.push_back({t, i});
  }
  sort(ans.begin(), ans.end());
 
  int t; cin>>t;
  while (t--) solve();
  return 0;
}