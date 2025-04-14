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
ll cnt[21][(1LL<<20)+5], cur;
unordered_map<ll, ll> idx;

void solve()
{
    ll n; cin>>n;
    ll xg, yg; cin>>xg>>yg;
    vector<pair<ll, ll>> v1(n/2), v2(n-n/2);
    vector<ll> ans(n+5);
    for (auto &[x, y]: v1) cin>>x>>y;
    for (auto &[x, y]: v2) cin>>x>>y;

    for (ll i=0; i<(1LL<<v1.size()); i++)
    {
        ll sx=0, sy=0;
        for (ll j=0; j<v1.size(); j++)
            if (i&(1LL<<j)) sx+=v1[j].first, sy+=v1[j].second;
        ll hsh=sx*mod+sy;
        if (idx.find(hsh)==idx.end()) idx[hsh]=++cur;
        ll pos=idx[hsh];
        ++cnt[__builtin_popcount(i)][pos];
    }
    for (ll i=0; i<(1LL<<v2.size()); i++)
    {
        ll sx=0, sy=0;
        for (ll j=0; j<v2.size(); j++)
            if (i&(1LL<<j)) sx+=v2[j].first, sy+=v2[j].second;
        ll hsh=(xg-sx)*mod+(yg-sy);
        if (idx.find(hsh)==idx.end()) continue;
        ll pos=idx[hsh];
        for (ll j=0; j<=n/2; j++) 
            ans[j+__builtin_popcount(i)]+=cnt[j][pos];
    }

    for (ll i=1; i<=n; i++) cout<<ans[i]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    // #ifndef ONLINE_JUDGE
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    // #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}