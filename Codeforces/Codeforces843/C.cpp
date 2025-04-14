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
set<ll> a[200005];

void solve()
{
    ll n; cin>>n;
    map<ll, ll> cnt;
    for (ll i=1; i<=n; i++)
    {
        map<ll, ll> cnta_i;
        ll k; cin>>k;
        for (ll j=1; j<=k; j++) 
        {
            ll x; cin>>x;
            ++cnta_i[x];
            a[i].insert(x);
            if (cnta_i[x]==2)
            {
                cnta_i[x+1]++;
                cnta_i.erase(x);
                a[i].erase(x);
                a[i].insert(x+1);
            }
        }
        for (auto j: cnta_i) cnt[j.first]++;
    }

    for (ll i=1; i<=n; i++)
    {
        bool check=true;
        for (auto j: a[i]) if (cnt[j]<2) check=false;
        if (check==true)
        {
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
    for (ll i=1; i<=n; i++) a[i].clear();
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