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
ll n, x[100005], k[100005];

ll binpow(ll a, ll n, ll mod)
{
    if (n==0) return 1;
    ll temp=binpow(a, n/2, mod);
    if (n%2==0) return temp*temp%mod;
    else return ((temp*temp)%mod)*a%mod;
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>x[i]>>k[i];
    ll souoc=1;
    for (ll i=1; i<=n; i++) souoc=(souoc*(k[i]+1))%mod;
    ll tong=1;
    for (ll i=1; i<=n; i++) tong=tong*(binpow(x[i], k[i]+1, mod)-1+mod)%mod*binpow(x[i]-1, mod-2, mod)%mod;
    ll tich=1, pi=1;
    for(int i=1; i<=n; i++){
        ll p = binpow(x[i], k[i]*(k[i]+1)/2, mod);
        tich=binpow(tich, k[i]+1, mod) * binpow(p, pi, mod) % mod;
        pi=(pi*(k[i]+1))%(mod-1);
    }
    cout<<souoc<<" "<<tong<<" "<<tich<<endl;
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