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
    string s; cin>>s;
    ll n=s.size(), z[n+5], f[n+5];
    memset(z, 0, sizeof(z));
    memset(f, 0, sizeof(f));

    for (ll i=1, l=0, r=0; i<n; i++)
    {
        if (i<=r) z[i]=min(r-i+1, z[i-l]);
        while (i+z[i]<n && s[z[i]]==s[i+z[i]]) ++z[i];
        if (i+z[i]-1>r) l=i, r=i+z[i]-1;
    }
    for (ll i=0; i<n; i++) cout<<z[i]<<" "; 
    cout<<endl;

    for (ll i=1; i<n; i++)
    {
        ll j=f[i-1];
        while (j>0 && s[i]!=s[j]) j=f[j-1];
        if (s[i]==s[j]) ++j;
        f[i]=j;
    }
    for (ll i=0; i<n; i++) cout<<f[i]<<" "; 
    cout<<endl;
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