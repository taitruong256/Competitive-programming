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
    ll n; cin>>n;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    set<ll> st;
    for (ll i=1; i<=n; i++) st.insert(a[i]);
    if (st.size()==1)
    {
        cout<<0<<endl;
        return;
    }
    if (st.find(1)!=st.end())
    {
        cout<<-1<<endl;
        return;
    }
    vector<pair<ll, ll>> ans, v;
    for (ll i=1; i<=n; i++) v.push_back({a[i], i});
    sort(v.begin(), v.end());
    while (v.front().first!=v.back().first)
    {
        for (ll i=1; i<n; i++) if (v[i].first>v[0].first) 
        {
            v[i].first=(v[i].first+v[0].first-1)/v[0].first;
            ans.push_back({v[i].second, v[0].second});
        }
        sort(v.begin(), v.end());
        if (v[0].first==1)
        {
            cout<<-1<<endl;
            return;
        }
    }
    cout<<ans.size()<<endl;
    for (auto [i, j]: ans) cout<<i<<" "<<j<<endl;
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