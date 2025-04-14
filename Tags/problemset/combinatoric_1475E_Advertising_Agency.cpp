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
ll fact[1005];

ll binpow(ll a, ll n)
{
    ll ans=1, p=1;
    while (n>0)
    {
        if (n%2==1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        n/=2;
    }
    return ans;
}

ll C(ll n, ll k)
{
    ll ans=1;
    ans=(ans*fact[n])%mod;
    ans=(ans*binpow(fact[k], mod-2))%mod;
    ans=(ans*binpow(fact[n-k], mod-2))%mod;
    return ans;
}

void solve()
{
    ll n, k; cin>>n>>k;       
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1, greater<ll>());
    ll x=0, y=0;
    for (ll i=k+1; i<=n; i++) if (a[i]==a[k]) ++x;
    for (ll i=k; i>=1; i--) if (a[i]==a[k]) ++y;
    cout<<C(x+y, y)<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    fact[0]=1;
    for (ll i=1; i<=1000; i++) fact[i]=(fact[i-1]*i)%mod;
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}