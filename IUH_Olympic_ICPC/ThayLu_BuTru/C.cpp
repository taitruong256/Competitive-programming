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
struct node 
{
    ll x, y, z;
};
node a[100005];

void solve()
{
    ll n; cin>>n;
    for (ll i=0; i<n; i++) cin>>a[i].x>>a[i].y>>a[i].z;
    map<ll, ll> s_a, s_b, s_c;
    map<pair<ll, ll>, ll> s_ab, s_bc, s_ac;
    map<tuple<ll, ll, ll>, ll> s_abc;
    for (ll i=0; i<n; i++)
    {
        ++s_a[a[i].x];
        ++s_b[a[i].y];
        ++s_c[a[i].z];
        ++s_ab[{a[i].x, a[i].y}];
        ++s_bc[{a[i].y, a[i].z}];
        ++s_ac[{a[i].x, a[i].z}];
        ++s_abc[{a[i].x, a[i].y, a[i].z}];
    }
    ll ans=0;
    for (auto [x, y]: s_a) ans=ans+y*(y-1)/2;
    for (auto [x, y]: s_b) ans=ans+y*(y-1)/2;
    for (auto [x, y]: s_c) ans=ans+y*(y-1)/2;
    for (auto [x, y]: s_ab) ans=ans-y*(y-1);
    for (auto [x, y]: s_bc) ans=ans-y*(y-1);
    for (auto [x, y]: s_ac) ans=ans-y*(y-1);
    for (auto [x, y]: s_abc) ans=ans+y*(y-1)/2*3;
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