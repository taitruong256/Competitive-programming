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
tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,
tree_order_statistics_node_update> T;             //find_by_order order_of_key
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;

void solve()
{
    ll n, k; cin>>n>>k;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=k; i++) T.insert({a[i], i});

    ll median1=(*T.find_by_order((k-1)/2)).first, ans=0;
    for (ll i=1; i<=k; i++) ans+=abs(median1-a[i]);
    cout<<ans<<" ";
    for (ll i=k+1; i<=n; i++)
    {
        T.insert({a[i], i});
        T.erase({a[i-k], i-k});
        ll median=(*T.find_by_order((k-1)/2)).first;
        ans+=abs(a[i]-median)-abs(a[i-k]-median1);
        if (k%2==0) ans+=median1-median;
        median1=median;
        cout<<ans<<" ";
    }
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