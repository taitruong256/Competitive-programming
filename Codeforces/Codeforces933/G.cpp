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
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

vector<pair<ll, ll>> adj[200005];
ll n, m, s, f;
map<ll, ll> d[200005];

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=m; i++)
    {
        ll u, v, c; cin>>u>>v>>c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    cin>>s>>f;
    d[s][-1]=0;
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
    pq.push({0, s, -1});
    while (!pq.empty())
    {
        auto [du, u, prec]=pq.top();
        pq.pop();
        if (du!=d[u][prec]) continue;
        for (auto [v, c]: adj[u]) 
        {
            if (d[v].find(c)==d[v].end() || d[u][prec]+(c!=prec)<d[v][c])
            {
                d[v][c]=d[u][prec]+(c!=prec);
                pq.push({d[v][c], v, c});
            }
        }
    }
    ll ans=1e18;
    for (auto [x, y]: d[f]) ans=min(ans, y);
    cout<<ans<<endl;
    for (ll i=1; i<=n; i++) adj[i].clear(), d[i].clear();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}