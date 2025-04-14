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
vector<pair<ll, ll>> adj[1005];
ll dp[1005][1005];

void solve()
{
    ll n, m; cin>>n>>m;
    for (ll i=0; i<m; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=1000; j++) dp[i][j]=1e18;
    ll s[n+5];
    for (ll i=1; i<=n; i++) cin>>s[i];
    
    dp[1][s[1]]=0; 
    //dp[i][j]: thoi gian toi thieu di tu dinh 1 den dinh i, su dung xe dap chi phi la j
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
    pq.push(make_tuple(0, s[1], 1));
    
    while (!pq.empty())
    {
        auto [duc, c, u]=pq.top(); pq.pop();
        if (duc>dp[u][c]) continue;
        for (auto [v, w]: adj[u]) if (dp[u][c]+c*w<dp[v][min(c, s[v])])
        {
            dp[v][min(c, s[v])]=dp[u][c]+c*w;
            pq.push({dp[v][min(c, s[v])], min(c, s[v]), v});
        }
    }
    ll ans=1e18;
    for (ll i=1; i<=1000; i++) ans=min(ans, dp[n][i]);
    cout<<ans<<endl;
    for (ll i=1; i<=n; i++) adj[i].clear();
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