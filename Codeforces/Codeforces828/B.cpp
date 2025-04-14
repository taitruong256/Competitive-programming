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
    ll n, q; cin>>n>>q;
    ll a[n+5];
    pair<ll, ll> chan, le;
    for (ll i=1; i<=n; i++) 
    {
        cin>>a[i];
        if (a[i]%2==0) chan.first+=a[i], ++chan.second;
        else le.first+=a[i], ++le.second;
    }

    while (q--)
    {
        ll type, x; cin>>type>>x;
        if (type==0)
        {
            if (x%2==0) chan.first+=x*chan.second;
            else le.first+=chan.first+x*chan.second, le.second+=chan.second, chan.first=0, chan.second=0;
        }
        else 
        {
            if (x%2==0) le.first+=x*le.second;
            else chan.first+=le.first+x*le.second, chan.second+=le.second, le.first=0, le.second=0;
        }  
        //cout<<"{"<<chan.first<<", "<<chan.second<<"}, {"<<le.first<<" "<<le.second<<"}\n";
        cout<<chan.first+le.first<<endl;
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