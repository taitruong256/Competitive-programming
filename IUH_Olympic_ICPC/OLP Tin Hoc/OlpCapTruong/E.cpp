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
ll mod = 1e9+7;
const ll inf = 1e9;

ll binpow(ll x, ll n, ll mod)
{
    if (n==0) return 1;
    ll t=binpow(x, n/2, mod);
    if (n%2==0) return (t*t)%mod;
    return ((t*t)%mod)*x%mod;
}

bool nt(ll n)
{
    for (ll i=2; i*i<=n; i++) if (n%i==0) return false;
    return true;
}

void solve()
{
    ll n, k, m; cin>>n>>k>>m;  
    ll giaithua[n+5];
    if (nt(m)==true)
    {
        giaithua[0]=1;
        mod=m;
        for (ll i=1; i<=n; i++) giaithua[i]=(giaithua[i-1]*i)%mod;
        // for (ll i=1; i<=n; i++) cout<<giaithua[i]<<" "; cout<<endl;
        ll ans=giaithua[n]*binpow(giaithua[n-k], mod-2, mod)%mod;
        ans=(ans*binpow(giaithua[k], mod-2, mod))%mod;
        cout<<ans;
    }
    else 
    {               
        giaithua[0]=1;
        for (ll i=1; i<=n; i++) giaithua[i]=(giaithua[i-1]*i)%mod;
        // for (ll i=1; i<=n; i++) cout<<giaithua[i]<<" "; cout<<endl;
        ll ans=giaithua[n]/(giaithua[n-k]*giaithua[k]);
        cout<<ans%m;
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