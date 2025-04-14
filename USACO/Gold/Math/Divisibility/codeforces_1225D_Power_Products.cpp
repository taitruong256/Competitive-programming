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

void solve()
{
    ll n, k; cin>>n>>k;
    ll a[n+5], ans=0;
    for (ll i=1; i<=n; i++) cin>>a[i];
    map<set<pair<ll, ll>>, ll> cnt;
    for (ll i=1; i<=n; i++)
    {                    
        ll x=2;
        set<pair<ll, ll>> st, bu;
        while (x*x<=a[i])
        {
            if (a[i]%x==0)
            {
                ll c=0;
                while (a[i]%x==0) 
                {
                    ++c;
                    a[i]/=x;
                }  
                if (c%k!=0) st.insert({x, c%k});
            }
            ++x;
        }
        if (a[i]>1) st.insert({a[i], 1});
        for (auto [c, x]: st) bu.insert({c, k-x});
        ans+=cnt[bu];
        cnt[st]++;
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