// /*==============================================================================================================
//          __                    __                                             _____     ______    _______
//         |  |                  |  |                                           /  __ \   / _____|  / ______|     
//       __|  |__              __|  |__                                         |_|  | |  | |       | |  
//      |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
//         |  |    _____   _     |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
//         |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
//         |  |_  | |_| | | |    |  |_  | |   | |_| | | |_| | | |  | | | |_| |    / /___   ____| |  | |___| |
//         \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  |_| \____ |   |______| |______/  \_______/
//                                                                         | |
//                                                                       __/ |
//                                                                      |___/  
//                              Nothing is impossible, only you think it is impossible                 
//                                      Try, try, try again until you succeed     
//                                         Pratice, practice, and practice
//                                        Where is your bug, delete it there
// I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
//                               You may not be the best, but must be the most effort
// ==============================================================================================================*/
// #include <bits/stdc++.h>
// //#include <ext/pb_ds/assoc_container.hpp>
// //#include <ext/pb_ds/tree_policy.hpp>
// using namespace std;
// //using namespace __gnu_pbds;
// #define ll long long
// //tree<ll, null_type, less<ll>, rb_tree_tag,
// //tree_order_statistics_node_update> T;             //find_by_order            order_of_key
// #define endl '\n'
// const ll mod = 1e9+7;
// const ll inf = 1e9;
// const ll maxn = 2e5+5;

// vector<ll> z_function(string s)
// {
//     ll n=s.size();
//     vector<ll> z(n);
//     for (ll i=1, l=0, r=0; i<n; i++)
//     {
//         if (i<=r) z[i]=min(z[i-l], r-i+1);
//         while (i+z[i]<n && s[z[i]]==s[i+z[i]]) ++z[i];
//         if (i+z[i]-1>r) l=i, r=i+z[i]-1;
//     }
//     return z;
// }

// void solve()
// {
//     string s; cin>>s;
//     ll n=s.size();
//     auto z=z_function(s);
    
//     ll mx=0, ans=-1;
//     for (ll i=1; i<n; i++) 
//     {
//         if (z[i]+i==n && z[i]<=mx)
//         {
//             cout<<s.substr(0, z[i]);
//             return;
//         }
//         mx=max(mx, z[i]);
//     }
//     cout<<"Just a legend\n";
// }

// int main()
// {
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     #ifndef ONLINE_JUDGE
//     freopen("_input.txt", "r", stdin);
//     freopen("_output.txt", "w", stdout);
//     #endif
//     solve();
//     return 0;
// }


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
const ll mod = 1e9+7, inf = 1e9, maxn = 1e6+5, base = 31;
string s;
ll power[maxn], hashs[maxn], n;

ll gethashs(ll l, ll r)
{
    return (hashs[r] - hashs[l-1]*power[r-l+1] + mod * mod) % mod;
}

bool check(ll x, ll hash)
{ 
    for (ll i=2; i<=n-x; i++) if (gethashs(i, i+x-1)==hash) return true;
    return false;
}

void solve()
{
    cin>>s; 
    n=s.size();
    s=" "+s;
    power[0]=1;
    for (ll i=1; i<=n; i++) power[i]=(power[i-1]*base)%mod;
    hashs[0]=0;
    for (ll i=1; i<=n; i++) hashs[i]=(hashs[i-1]*base+s[i]-'a'+1)%mod;

    vector<ll> pos;
    for (ll i=1; i<=n; i++) if (gethashs(1, i)==gethashs(n-i+1, n)) pos.push_back(i);
    // for (auto i: pos) cout<<i<<" "; cout<<endl;

    ll l=0, r=pos.size()-1, ans=-1, mid=1;
    while (l<=r)
    {
        mid=(l+r)/2;
        if (check(pos[mid], gethashs(1, pos[mid]))==true) ans=pos[mid], l=mid+1;
        else r=mid-1;
    }
    if (ans==-1) cout<<"Just a legend";
    else cout<<s.substr(1, ans)<<endl;
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