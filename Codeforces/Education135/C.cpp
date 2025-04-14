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

bool comp(ll a, ll b)
{
    return a>b;
}

ll chuyen(ll x)
{
    ll cnt=0;
    while (x>0) ++cnt, x/=10;
    return cnt;
}

void solve()
{
    ll n, x; cin>>n; 
    multiset<ll> a, b, c;
    for (ll i=1; i<=n; i++) cin>>x, a.insert(x);
    for (ll i=1; i<=n; i++) cin>>x, b.insert(x);
    c=a;
    
    ll ans=0;
    for (auto it: c)
    {
        if (b.find(it)!=b.end())
        {
            b.erase(b.find(it));
            a.erase(a.find(it));
        }
    }

    while (!a.empty())
    {
        ll x=*a.rbegin();
        ll z=*b.rbegin();

        if (x>z)
        {
            a.erase(a.find(x));
            ll y=chuyen(x);
            if (x!=y) ++ans;
            if (b.find(y)!=b.end()) b.erase(b.find(y));
            else a.insert(y);
            if (a.empty()) break;
        }
        else 
        {
            b.erase(b.find(z));
            ll t=chuyen(z);
            if (z!=t) ++ans;
            if (a.find(t)!=a.end()) a.erase(a.find(t));
            else b.insert(t);
        }
    }
    cout<<ans<<endl;
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