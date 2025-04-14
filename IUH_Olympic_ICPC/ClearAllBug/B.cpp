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
    ll w, h, q; cin>>w>>h>>q;    
    multiset<ll> low_w, high_w, low_h, high_h, d_w, d_h;
    high_w.insert(0); high_w.insert(w); low_w.insert(0); low_w.insert(-w); d_w.insert(w);
    high_h.insert(0); high_h.insert(h); low_h.insert(0); low_h.insert(-h); d_h.insert(h);

    for (ll i=1; i<=q; i++)
    {
        char c; cin>>c;
        ll pos; cin>>pos;
        if (c=='H')  //ngang
        {  
            ll l=-*low_h.lower_bound(-pos);
            ll r=*high_h.lower_bound(pos);
            high_h.insert(pos);
            low_h.insert(-pos);
            d_h.erase(d_h.find(r-l));
            d_h.insert(pos-l);
            d_h.insert(r-pos);
            cout<<(*d_h.rbegin())*(*d_w.rbegin())<<endl;
        }
        else  //doc
        {   
            ll l=-*low_w.lower_bound(-pos);
            ll r=*high_w.lower_bound(pos);
            high_w.insert(pos);
            low_w.insert(-pos);
            d_w.erase(d_w.find(r-l));
            d_w.insert(pos-l);
            d_w.insert(r-pos);
            cout<<(*d_h.rbegin())*(*d_w.rbegin())<<endl;
        }
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