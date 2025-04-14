/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
         __                    __
        |  |                  |  |         
     ___|  |__             ___|  |__  
    |__ |   __|           |__ |   __| 
        |  |    ____    _     |  |    ____  __  __  ____    _____    _____
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \
        |  |_  | |_| | | |    |  |   | |   | \_/ | | |_| | | /  \ | | |_| |
        \____\ \____/| |_|    \__\   |_|   \_____/ \_____/ |_|  | | \__   |
                                                                        | |
                                                                      __/ |
                                                                     |___/  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const ll mod = 1e9+7;
const ll inf = 1e9;
ll inv;

ll binpow(ll a, ll n, ll mod)
{
    if (n==0) return 1;
    ll temp=binpow(a, n/2, mod);
    if (n%2==0) return temp*temp%mod;
    else return ((temp*temp)%mod)*a%mod;
}

ll calc(ll l, ll r)
{
    l%=mod;
    r%=mod;
    ll sum=0;
    sum+=(r*(r+1)%mod*inv%mod);
    sum-=(l*(l-1)%mod*inv%mod);
    if (sum<0) sum+=mod;
    return sum;
}

void solve()
{
    ll n; cin>>n;
    inv=binpow(2, mod-2, mod);
    ll ans=0;
    for (ll l=1; l<=n;) 
    {
        ll r=n/(n/l);  
        ans=(ans+calc(l, r)*(n/l)%mod)%mod; cout<<l<<" "<<r<<" "<<ans<<endl;
        l=r+1;  
    }
    cout<<ans;
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