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
    deque<ll> p;
    vector<pair<ll, ll>> c;
    ll cnt=0;
    for (ll i=0; i<n; i++)
    {
        ll x; cin>>x;
        if (x==1) ++cnt;
        p.push_back(x);
    }
    if (cnt==0)
    {
        cout<<"NO\n";
        return;
    }
    while (p.front()!=1)
    {
        ll x=p.back(); p.pop_back();
        p.push_front(x);
    }
    for (ll i=0; i<n; i++) c.push_back({p[i], -i});
    sort(c.begin(), c.end());
    ll ans[n+5];
    for (ll i=0; i<n; i++) ans[-c[i].second]=n-i;
    reverse(ans, ans+n);
    vector<ll> st;
    for (ll i=0; i<n; i++)
    {
        while (!st.empty() && ans[n-1-i]>=st.back()) st.pop_back();
        st.push_back(ans[n-1-i]);  
        if (st.size()!=p[i])
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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