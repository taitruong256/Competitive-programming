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
    ll n, m, k; cin>>n>>m>>k;
    if (m==0)
    {
        cout<<min(n, k+1);
        return;
    }
    vector<pair<ll, ll>> a;
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        if (u>v) swap(u, v);
        if (u+1==v) a.push_back({u, v});
    }
    sort(a.begin(), a.end());
    a.push_back({1e9, 1e9+1});

    ll x=a[0].first, y=x+1;
    set<pair<ll, ll>> st;
    for (ll i=0; i<=m; i++)
    {
        if (a[i].second==y) continue;
        else if (a[i].first==y) ++y;
        else 
        {
            st.insert({x, y});
            x=a[i].first;
            y=x+1;
        }
    }
    vector<pair<ll, ll>> v;
    for (auto [x, y]: st) v.push_back({x, y});

    ll ans=0;
    for (ll i=0; i<v.size(); i++)
    {
        ll K=k;
        ll res=v[i].second-v[i].first+1;
        ll last=v[i].second;
        for (ll j=i+1; j<v.size(); j++)
            if (K>=a[j].first-a[j-1].second)
            {
                res+=a[j].first-a[j-1].second+a[j].second-a[j].first;
                K-=a[j].first-a[j-1].second;
                last=v[j].second;
            }
            else break;
        ans=max(ans, res+K);
    } 
    cout<<min(ans, n);
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