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
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define ll long long
//tree<ll, null_type, less<ll>, rb_tree_tag,
//tree_order_statistics_node_update> T;             //find_by_order            order_of_key
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
ll n, s, cost[100005];
pair<ll, ll> a[100005];
ll b[100005];
 
bool check(ll x)
{
    for (ll i=1; i<=n; i++) b[i]=a[i].first+a[i].second*x;
    sort(b+1, b+n+1);
    ll sum=0;
    for (ll i=1; i<=x; i++) sum+=b[i];
    return sum<=s;
}
 
void solve()
{
    cin>>n>>s;
    for (ll i=1; i<=n; i++) cin>>a[i].first, a[i].second=i;
    ll l=1, r=n, ans=0;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (check(mid)==true) ans=mid, l=mid+1;
        else r=mid-1;
    }
    cout<<ans<<" ";
    for (ll i=1; i<=n; i++) b[i]=a[i].first+a[i].second*ans;
    sort(b+1, b+n+1);
    ll sum=0;
    for (ll i=1; i<=ans; i++) sum+=b[i];
    cout<<sum;
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
