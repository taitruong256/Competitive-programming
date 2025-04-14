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
    ll n, k ;cin>>n>>k;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    deque<ll> dq;
    for (ll i=1; i<=k-1; i++) dq.push_back(a[i]);
    ll mx=-inf;
    for (ll i=k; i<=n; i++)
    {
        dq.push_back(a[i]);
        if (dq.size()>k) dq.pop_front();
        vector<ll> v;
        while (!dq.empty()) 
        {
            v.push_back(dq.front()); 
            dq.pop_front();
        }
        for (auto i: v) dq.push_back(i);
        sort(v.begin(), v.end());
        mx=max(mx, v[k/2]);  
    } 

    ll ans=0;
    dq.clear();
    for (ll i=1; i<=k-1; i++) dq.push_back(a[i]);
    for (ll i=k; i<=n; i++)
    {
        dq.push_back(a[i]);
        if (dq.size()>k) dq.pop_front();
        vector<ll> v;
        while (!dq.empty()) 
        {
            v.push_back(dq.front()); 
            dq.pop_front();
        }
        for (auto i: v) dq.push_back(i);
        sort(v.begin(), v.end());
        if (v[k/2]==mx) ++ans;  
    } 
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}