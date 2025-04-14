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
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

void solve()
{
    ll n, k; cin>>n>>k;
    ll a[2*n];
    for (ll i=1; i<=2*n; i++) cin>>a[i];
    map<ll, ll> cntleft, cntright;
    set<ll> candleft, candright, candmid;
    for (ll i=1; i<=n; i++)
    {
        ++cntleft[a[i]];
        if (cntleft[a[i]]==2) candleft.insert(a[i]);
    }
    for (ll i=n+1; i<=2*n; i++)
    {
        ++cntright[a[i]];
        if (cntright[a[i]]==2) candright.insert(a[i]);
    }
    for (ll i=1; i<=n; i++) if (cntleft[a[i]]==1) candmid.insert(a[i]);
    vector<ll> ans1, ans2;
    assert(candleft.size()==candright.size());
    k*=2;
    while (k>0)
    {
        if (candleft.size()>0)
        {
            ll x=*candleft.begin(); 
            candleft.erase(x);
            ans1.push_back(x);
            ans1.push_back(x);
            ll y=*candright.begin();
            candright.erase(y);
            ans2.push_back(y);
            ans2.push_back(y);
            k-=2;
        }
        else 
        {
            ll x=*candmid.begin(); 
            candmid.erase(x);
            ans1.push_back(x);
            ans2.push_back(x);
            k-=1;
        }
    }
    for (auto i: ans1) cout<<i<<" "; cout<<endl;
    for (auto i: ans2) cout<<i<<" "; cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}