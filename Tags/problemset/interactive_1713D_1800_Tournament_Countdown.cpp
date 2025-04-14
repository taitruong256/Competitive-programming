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
const ll maxn = 2e5+5;

ll query(ll x, ll y)
{
    cout<<"? "<<x<<" "<<y<<endl;
    ll t; cin>>t;
    return t;
}

void solve()
{
    ll n; cin>>n;
    vector<ll> v;
    for (ll i=1; i<=(1<<n); i++) v.push_back(i);
    while (v.size()>2)
    {
        vector<ll> t;
        for (ll i=0; i<v.size(); i+=4)
        {
            ll q=query(v[i], v[i+2]);
            if (q==1) t.push_back(v[i]), t.push_back(v[i+3]);
            else if (q==2) t.push_back(v[i+2]), t.push_back(v[i+1]);
            else t.push_back(v[i+1]), t.push_back(v[i+3]);
        }
        swap(v, t);
        // for (auto i: v) cout<<i<<" "; cout<<endl;
    }

    ll ans=1;
    if (v.size()==2) 
    {
        cout<<"? "<<v[0]<<" "<<v[1]<<endl;
        ll x; cin>>x;
        if (x==1) ans=v[0];
        else ans=v[1];
    }
    cout<<"! "<<ans<<endl;
}

int main()
{
    ll t; cin>>t;
    // #ifndef ONLINE_JUDGE
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    // #endif
    while (t--) solve();
    return 0;
}