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
                                          Noi dau + Suy ngam = Tien bo 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;

void solve()
{
    ll n, m, x; cin>>n>>m;
    vector<ll> v1, v2;
    for (ll i=0; i<n/2; i++) cin>>x, v1.push_back(x);
    for (ll i=n/2; i<n; i++) cin>>x, v2.push_back(x);

    vector<ll> val1, val2;
    for (ll i=0; i<(1LL<<(n/2)); i++)
    {
        ll s=0;
        for (ll j=0; j<n/2; j++)
            if (i&(1LL<<j)) s=(s+v1[j])%m;
        val1.push_back(s);
    }
    for (ll i=0; i<(1LL<<(n-n/2)); i++)
    {
        ll s=0;
        for (ll j=0; j<(n-n/2); j++)
            if (i&(1LL<<j)) s=(s+v2[j])%m;
        val2.push_back(s);
    }
    sort(val1.begin(), val1.end());
    sort(val2.begin(), val2.end());
    ll ans=0;
    for (auto val: val1)
    {
        ll pos;
        pos=lower_bound(val2.begin(), val2.end(), m-val)-val2.begin()-1;
        if (pos!=-1) ans=max(ans, (val+val2[pos])%m);
        pos=lower_bound(val2.begin(), val2.end(), 2*m-val)-val2.begin()-1;
        if (pos!=-1) ans=max(ans, (val+val2[pos])%m);
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