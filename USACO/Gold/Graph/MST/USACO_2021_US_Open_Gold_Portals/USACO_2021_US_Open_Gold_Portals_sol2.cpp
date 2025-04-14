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

vector<pair<ll, ll>> adj[200005];
ll d[200005], used[200005];

void solve()
{
    ll n; cin>>n;
    for (ll i=1; i<=n; i++)
    {
        ll c, p1, p2, p3, p4; cin>>c>>p1>>p2>>p3>>p4;
        adj[p1].push_back({p2, 0});
        adj[p2].push_back({p1, 0});
        adj[p3].push_back({p4, 0});
        adj[p4].push_back({p3, 0});
        adj[p1].push_back({p3, c});
        adj[p3].push_back({p1, c});
    }
  
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (ll i=1; i<=2*n; i++) d[i]=1e18;
    pq.push({0, 1});
    d[1]=0;
    while (!pq.empty())
    {
        auto [W, u]=pq.top(); pq.pop();
        if (W>d[u] || used[u]==true) continue;
        used[u]=true;  
        for (auto [v, w]: adj[u]) if (used[v]==false && w<d[v])
        {
            d[v]=w;
            pq.push({d[v], v});
        }
    }
    ll ans=0;
    for (ll i=1; i<=2*n; i++) ans+=d[i];
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