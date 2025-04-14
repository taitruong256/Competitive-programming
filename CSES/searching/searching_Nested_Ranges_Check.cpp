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
//tree_order_statistics_node_update> T;             //find_by_order order_of_key
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
struct range
{
    ll l, r, id;
    bool operator < (const range &other) const 
    {
        if (l==other.l) return r>other.r;
        return l<other.l;
    }
};

void solve()
{
    ll n; cin>>n;
    range a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i].l>>a[i].r, a[i].id=i;
    sort(a+1, a+n+1);
    
    bool contains[n+5], contained[n+5];
    memset(contains, false, sizeof(contains));
    memset(contained, false, sizeof(contained));
    ll mx=0, mn=1e10;
    for (ll i=1; i<=n; i++) 
    {
        contained[a[i].id]=(a[i].r<=mx);
        mx=max(mx, a[i].r);
    }
    for (ll i=n; i>=1; i--)
    {
        contains[a[i].id]=(a[i].r>=mn);
        mn=min(mn, a[i].r);
    }

    for (ll i=1; i<=n; i++) cout<<contains[i]<<" "; cout<<endl;
    for (ll i=1; i<=n; i++) cout<<contained[i]<<" "; cout<<endl;
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