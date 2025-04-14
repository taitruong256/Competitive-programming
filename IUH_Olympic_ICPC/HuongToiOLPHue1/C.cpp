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
const ll maxn = (1LL<<18)+5;
set<pair<ll, ll>> _left, _right;
ll a, b, c, n; 

ll merges(pair<ll, ll> x, pair<ll, ll> y)
{
  return (((x.first*y.first)%c)*a%c+((x.second*y.second)%c)*b%c)%c;
}

void solve()
{
    _left.clear();
    _right.clear();
    cin>>a>>b>>c>>n;
    vector<ll> v;
    ll m=0;
    for (ll i=1; i<=n; i++)
    {
        ll x, y; cin>>x>>y;
        for (ll j=1; j<=y; j++) v.push_back(x);
        m+=y;
    }
    ll l=m/2, r=m-m/2;


    for (ll mask=0; mask<(1LL<<l); mask++)
    {
      ll x=1, y=1;
      for (ll i=0; i<l; i++) 
      {
        if (mask&(1LL<<i)) x=(x*v[i]);
        else y=(y*v[i]);
        _left.insert({x, y});
      }
    }


    for (ll mask=0; mask<(1LL<<r); mask++)
    {
      ll x=1, y=1;
      for (ll i=0; i<r; i++) 
      {
        if (mask&(1LL<<i)) x=(x*v[l+i]);
        else y=(y*v[l+i]);
        _right.insert({x, y});
      }
    }

    // for (auto i: _left) cout<<i.first<<" "<<i.second<<endl; cout<<endl;
    // for (auto i: _right) cout<<i.first<<" "<<i.second<<endl; cout<<endl;

    for (auto i: _left)
      for (auto j: _right)
        if (merges(i, j)==0)
        {
          cout<<"YES\n";
          return;
        }
    cout<<"NO\n";
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