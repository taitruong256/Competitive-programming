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

void solve()
{
    ll n, s; cin>>n>>s;
    pair<ll, ll> a[n+5]; 
    for (ll i=1; i<=n; i++) cin>>a[i].first, a[i].second=i;
    sort(a+1, a+n+1);
    map<ll, vector<pair<ll, ll>>> mp;
    for (ll i=1; i<=n-1; i++)
        for (ll j=i+1; j<=n; j++) 
            mp[a[i].first+a[j].first].push_back({a[i].second, a[j].second});
    
    for (auto x: mp)
    {
        ll y=s-x.first;
        if (mp.find(y)!=mp.end())
        {
            for (auto i: x.second)
                for (auto j: mp[y])
                    if (i.first!=j.first && i.first!=j.second && i.second!=j.first && i.second!=j.second)
                    {
                        cout<<i.first<<" "<<i.second<<" "<<j.first<<" "<<j.second;
                        return;
                    }
        }
    }
    cout<<"IMPOSSIBLE";
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