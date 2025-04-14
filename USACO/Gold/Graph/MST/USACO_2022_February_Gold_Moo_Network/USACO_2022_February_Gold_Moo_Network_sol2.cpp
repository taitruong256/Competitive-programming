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
                                          Noi dau + Suy ngam = Tien bo 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;

ll sqr(ll x)
{
    return x*x;
}

ll dist(pair<ll, ll> a, pair<ll, ll> b)
{
    return sqr(a.first-b.first)+sqr(a.second-b.second);
}

ll n, d[100005], used[100005];
pair<ll, ll> p[100005], last[15];
vector<pair<ll, ll>> adj[100005];

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>p[i].first>>p[i].second;
    sort(p+1, p+n+1);
    
    for (ll i=0; i<=10; i++) last[i]={-1LL, -1LL};
    for (ll i=1; i<=n; i++)
    {
        for (ll j=0; j<=10; j++) if (last[j]!=make_pair(-1LL, -1LL))
        {
            ll u=i, v=last[j].first, w=dist(p[i], {last[j].second, j});
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        last[p[i].second]={i, p[i].first};
    }

    //prim
    for (ll i=1; i<=n; i++) d[i]=1e18;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    d[1]=0;
    while (!pq.empty())
    {
        auto [W, u]=pq.top(); pq.pop();
        if (W>d[u]) continue;
        used[u]=1;
        for (auto [v, w]: adj[u]) if (used[v]==0 && w<d[v])
        {
            d[v]=w;
            pq.push({d[v], v});
        }
    }
    ll ans=0;
    for (ll i=1; i<=n; i++) ans+=d[i];
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    // #ifndef ONLINE_JUDGE
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    // #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}