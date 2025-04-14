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
                                        Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll inf = 1e18;
const ll mod = 998244353;
vector<ll> a[1000005];
ll cnt[1000005];

ll binpow(ll x, ll n, ll mod)
{
    ll ans=1;
    while (n>0)
    {
        if (n%2==1) ans=(ans*x)%mod;
        x=(x*x)%mod;
        n/=2;
    }
    return ans;
}

void solve()
{
    ll n; cin>>n;
    for (int i=1; i<=n; i++)
    {
        ll k; cin>>k;
        for (ll j=1; j<=k; j++) 
        {
            ll x; cin>>x;
            ++cnt[x];
            a[i].push_back(x);
        }
    }
    ll invN = binpow(n, mod-2, mod), ans=0;
    for (int i=1; i<=n; i++){
    ll invK=binpow(a[i].size(),mod-2, mod);
    for (auto x: a[i])
        ans=(ans+((invN*invK)%mod)*(cnt[x]*invN%mod))%mod;
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}