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
    ll n, m; cin>>n>>m;
    ll a[n+5], b[m+5];
    map<ll, ll> cnt;
    for (ll i=1; i<=n; i++) 
    {
        cin>>a[i];
        ++cnt[a[i]];
    }
    for (ll i=1; i<=m; i++) cin>>b[i];
    
    multiset<ll> guest, table;
    for (auto i: cnt) guest.insert(i.second);
    for (ll i=1; i<=m; i++) table.insert(b[i]);

    // cout<<"  --guest:   "; for (auto i: guest) cout<<i<<" "; cout<<endl;
    // cout<<"  --table:   "; for (auto i: table) cout<<i<<" "; cout<<endl;

    ll ans=0;
    while (!guest.empty())
    {
        ll t=*guest.rbegin();
        if (table.empty()) break;
        auto it=table.lower_bound(t);
        if (it==table.end()) --it;
        ans+=min(t, *it);
        guest.erase(guest.find(t));
        table.erase(table.find(*it));
        if (t>*it) guest.insert(t-*it);
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}