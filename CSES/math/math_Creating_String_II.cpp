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
ll fact[1000005], rev[1000005];
string s;

ll binpow(ll a, ll n, ll mod)
{
    if (n==0) return 1;
    ll temp=binpow(a, n/2, mod);
    if (n%2==0) return temp*temp%mod;
    else return ((temp*temp)%mod)*a%mod;
}

void solve()
{
    cin>>s;
    ll n=s.size();   
    ll cnt[26];
    memset(cnt, 0, sizeof(cnt));
    for (auto c: s) ++cnt[c-'a'];
    fact[0]=rev[0]=1;
    for (ll i=1; i<=n; i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
        rev[i]=binpow(fact[i], mod-2, mod);
    }
    ll ans=fact[n];  
    for (ll i=0; i<26; i++) ans=(ans*rev[cnt[i]])%mod;
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