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

void solve()
{
    ll n; cin>>n;
    ll v[n+5], d[n+5], p[n+5];
    vector<ll> ans;
    for (ll i=1; i<=n; i++) cin>>v[i]>>d[i]>>p[i];

    bool check[n+5];
    memset(check, true, sizeof(check));
    for (ll i=1; i<=n; i++) 
    {
        if (p[i]>=0)
        {
            ans.push_back(i);
            for (ll j=i+1; j<=n; j++) if (p[j]>=0)
            {
                p[j]-=v[i];
                --v[i];
                if (v[i]<0) break;
            }
            ll s=0;
            for (ll j=i+1; j<=n; j++) if (check[j]==true)
            {
                if (p[j]>=0) p[j]-=s;
                if (p[j]<0) s+=d[j], check[j]=false;
            }
        }
        // for (ll j=1; j<=n; j++) cout<<p[j]<<" "; cout<<endl;
    }
    cout<<ans.size()<<endl;
    for (auto i: ans) cout<<i<<" "; 
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