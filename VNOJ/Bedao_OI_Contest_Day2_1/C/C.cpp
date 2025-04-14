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
                                       Where is the bug, delete it there
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
ll n, m, a[205], b[205], c[205];
vector<ll> adj[205];

void solve()
{
    cin>>n>>m;
    for (ll i=0; i<n; i++) cin>>a[i]>>b[i]>>c[i];
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        --u;
        --v;
        adj[u].push_back(v);
    }
    ll ans=0;
    for (ll mask=0; mask<(1LL<<n); mask++)
    {
        ll now_mask=mask;
        ll suma=0, sumb=0, sumc=0;
        for (ll i=0; i<n; i++) if (mask&(1LL<<i)) 
            for (ll j: adj[i]) now_mask|=(1LL<<j);
        for (ll i=0; i<n; i++) if (now_mask&(1LL<<i))
        {
            suma+=a[i];
            sumb+=b[i];
            sumc+=c[i];
        }
        ans=max(ans, suma*sumb-sumc);
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("restaurant.inp", "r", stdin);
    freopen("restaurant.out", "w", stdout);
    solve();
    return 0;
}