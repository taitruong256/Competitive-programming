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
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;

void solve()
{
    ll n, m; cin>>n>>m;
    vector<vector<ll>> a(n+5);
    for (ll i=0; i<n+5; i++) a[i].resize(m+5, 0);
    
    for (ll i=0; i<n; i++)
        for (ll j=0; j<m; j++) cin>>a[i][j];

    ll ans=0;
    for (ll j=0; j<m; j++)
    {
        vector<ll> v;
        for (ll i=0; i<n ;i++) v.push_back(a[i][j]);
        sort(v.begin(), v.end());
        for (ll i=n-1; i>=0; i--)
        {
            ll lon=lower_bound(v.begin(), v.end(), v[i])-v.begin();
            ll bang=upper_bound(v.begin(), v.end(), v[i])-lower_bound(v.begin(), v.end(), v[i]);
            ll nho=n-lon-bang;
            ans+=v[i]*lon*bang-v[i]*nho*bang;   
            i=lon;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
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