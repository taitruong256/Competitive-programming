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

void solve()
{
    string s; cin>>s; 
    ll n=s.size();
    ll m; cin>>m;
    string t[m+5];
    for (ll i=0; i<m; i++) cin>>t[i];

    ll last=0;
    vector<pair<ll, ll>> ans;
    while (last<n)
    {
        ll idx=-1, from=-1, max_reach=-1;
        for (ll i=last; i>=0; i--)
        {
            for (ll j=0; j<m; j++)
            {
                ll k=t[j].size();
                if (i+k-1<=n-1 && s.substr(i, k)==t[j])
                {
                    if (i+k-1>max_reach)
                    {
                        max_reach=i+k-1;
                        idx=j;
                        from=i;
                    }
                }
            }
        }

        if (max_reach>=last)
        {
            last=max_reach+1;
            ans.push_back({idx+1, from+1});
        }
        else
        {
            cout<<-1<<endl;
            return;
        }
    }
    cout<<ans.size()<<endl;
    for (auto [x, y]: ans) cout<<x<<" "<<y<<endl;
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