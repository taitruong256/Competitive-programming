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
const ll mod = 1e9+7;

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
    ll x, n; cin>>x>>n;
    vector<ll> uoc;
    ll i=2;
    while (i*i<=x)
    {
        if (x%i==0)
        {
            uoc.push_back(i);
            while (x%i==0) x/=i;
        }
        ++i;
    }
    if (x>1) uoc.push_back(x);

    vector<pair<ll, ll>> lt;
    for (auto i: uoc)
    {
        ll p=1;
        while (p<=n/i)
        {
            p=p*i;
            lt.push_back({p, i});
        }
    }
    ll ans=1;
    for (auto [p, i]: lt)
    {
        ll x=binpow(i, n/p, mod);
        ans=(ans*x)%mod;
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