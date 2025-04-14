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
    vector<ll> chan, le;
    for (ll i=1; i<=n; i++) if (a[i]%2==0) chan.push_back(i); else le.push_back(i);
    vector<pair<ll, ll>> ans;
    if (a[1]%2==0)
    {
        for (ll i=chan.size()-2; i>=0; i--) ans.push_back({chan[i], chan[i+1]});
        for (auto i: le) ans.push_back({1, i});
        cout<<ans.size()<<endl;
        for (auto i: ans) cout<<i.first<<" "<<i.second<<endl;
        return;
    }
    else 
    {
        for (ll i=le.size()-2; i>=0; i--) ans.push_back({le[i], le[i+1]});
        for (auto i: chan) ans.push_back({1, i});
        cout<<ans.size()<<endl;
        for (auto i: ans) cout<<i.first<<" "<<i.second<<endl;
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}