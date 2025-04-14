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
    vector<ll> v1, v2;
    for (ll i=0; i<n/2; i++)
    {
        ll x; cin>>x;
        v1.push_back(x);
    }
    for (ll i=n/2; i<n; i++)
    {
        ll x; cin>>x;
        v2.push_back(x);
    }

    vector<ll> v;
    for (ll i=0; i<(1<<v1.size()); i++)
    {
        ll sum=0;
        for (ll j=0; j<v1.size(); j++) if (i&(1<<j)) sum+=v1[j];
        v.push_back(sum);
    }
    sort(v.begin(), v.end());

    ll ans=0;
    for (ll i=0; i<(1<<v2.size()); i++)
    {
        ll sum=0;
        for (ll j=0; j<v2.size(); j++) if (i&(1<<j)) sum+=v2[j];
        ans+=upper_bound(v.begin(), v.end(), m-sum)-lower_bound(v.begin(), v.end(), m-sum);
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