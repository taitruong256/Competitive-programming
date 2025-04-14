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
    vector<ll> pos[30];
    string s; cin>>s;
    ll n=s.size();
    vector<ll> ans;
    for (ll i=0; i<n; i++) pos[s[i]-'a'].push_back(i+1);
   
    if (s[0]>s[n-1])
    {
        for (ll i=s[0]; i>=s[n-1]; i--) 
            for (auto j: pos[i-'a']) ans.push_back(j);
        cout<<abs(s[0]-s[n-1])<<" "<<ans.size()<<endl;
        for (auto i: ans) cout<<i<<" "; cout<<endl;
        return;
    }
    else 
    {
        for (ll i=s[0]; i<=s[n-1]; i++) 
            for (auto j: pos[i-'a']) ans.push_back(j);
        cout<<abs(s[0]-s[n-1])<<" "<<ans.size()<<endl;
        for (auto i: ans) cout<<i<<" "; cout<<endl;
        return;
    }
    for (auto &i: pos) i.clear();
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