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
const ll base = 311;
ll n, m, power[2000005], hash_s[2000005];
string s;

ll get_hash(ll l, ll r)
{
    return (hash_s[r]-hash_s[l-1]*power[r-l+1]+mod*mod)%mod;
}

bool comp(ll a, ll b)
{
    if (s[a]!=s[b]) return s[a]<s[b];
    if (get_hash(a, a+m-1)==get_hash(b, b+m-1)) return false;
    ll l=1, r=m, ans=1;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (get_hash(a, a+mid-1)==get_hash(b, b+mid-1)) ans=mid, l=mid+1;
        else r=mid-1;
    }            
    return (s[a+ans]<s[b+ans]);
}

void solve()
{
    cin>>s;
    n=s.size()*2; m=n/2;
    s+=s;
    s=" "+s;
    power[0]=1;
    for (ll i=1; i<=n; i++) power[i]=(power[i-1]*base)%mod;

    hash_s[0]=0;
    for (ll i=1; i<=n; i++) hash_s[i]=(hash_s[i-1]*base+s[i]-'a'+1)%mod;
    
    ll mn=1;
    for (ll i=2; i<=m; i++) if (comp(i, mn)==true) mn=i;  
    cout<<s.substr(mn, m);
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