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
    priority_queue<pair<ll, ll>> pq;
    for (ll i=1; i<=n; i++)
    {
        ll deg; cin>>deg;
        if (deg>0) pq.push({deg, i});
    }

    vector<pair<ll, ll>> ans;
    while (!pq.empty())
    {
        auto [degu, u]=pq.top(); pq.pop();
        vector<pair<ll, ll>> temp;
        while (degu>0)
        {
            if (pq.empty()) 
            {
                cout<<"IMPOSSIBLE";
                return;
            }
            auto [degv, v]=pq.top(); pq.pop();
            ans.push_back({u, v});
            if (--degv>0) temp.push_back({degv, v});
            --degu;
        }
        for (auto [degv, v]: temp) pq.push({degv, v});
    }
    cout<<ans.size()<<endl;
    for (auto [u, v]: ans) cout<<u<<" "<<v<<endl;
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