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
    ll g=a[1];
    for (ll i=2; i<=n; i++) g=__gcd(g, a[i]); 
    if (g>1)
    {
        cout<<-1<<endl;
        return;
    }
    map<ll, ll> lst;
    for (ll i=1; i<=n; i++) lst[a[i]]=i;
    vector<pair<ll, ll>> v;
    for (auto it: lst) v.push_back({it.second, it.first});
    ll mx=-1;
    for (ll i=v.size()-1; i>=0; i--)
        for (ll j=i; j>=0; j--) if (__gcd(v[i].second, v[j].second)==1) 
            mx=max(mx, v[i].first+v[j].first);
    ll pos=-1;
    for (ll i=1; i<=n; i++) if (a[i]==1) pos=i;
    if (pos!=-1) mx=max(mx, pos+n);
    cout<<mx<<endl;
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