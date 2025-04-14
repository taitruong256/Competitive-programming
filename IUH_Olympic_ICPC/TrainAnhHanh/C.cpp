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
#define ll int
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
const ll inf = 1e9;

ll luythua(ll p, ll k)
{
    ll x=1;
    for (ll i=1; i<=k; i++) 
    {
        if (inf/p<x) return inf;
        x=x*p;
    }
    return x;
}

ll tinh(ll r, ll k)
{
    ll ans=0;
    for (ll i=1; i<=r; i++) 
    {
        ans=ans+r/i;
        ans=ans-r/luythua(i, k);
    }
    return ans;
}

void solve()
{
    ll l, r, k; cin>>l>>r>>k;
    cout<<tinh(r, k)-tinh(l-1, k);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("divexp.inp", "r", stdin);
    // freopen("divexp.out", "w", stdout);
    solve();
    return 0;
}