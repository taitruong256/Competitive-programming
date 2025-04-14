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
struct edge
{
    ll a, b, c, d, h;
};
ll n, m, k, x[100005];
set<ll> row[100005];
vector<edge> adj[100005];
map<ll, ll> dist[100005];

void solve()
{
    cin>>n>>m>>k;
    for (ll i=1; i<=n; i++) cin>>x[i];
    for (ll i=1; i<=k; i++)
    {
        ll a, b, c, d, h; cin>>a>>b>>c>>d>>h;
        row[a].insert(b);
        row[c].insert(d);
        adj[a].push_back({a, b, c, d, h});
    }
    row[1].insert(1);
    row[n].insert(m);
    for (ll i=1; i<=n; i++)
        for (auto j: row[i])
            dist[i][j]=1e18;
    dist[1][1]=0;
    for (ll i=1; i<=n; i++)
    {
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        for (auto j: row[i]) 
            if (dist[i][j]!=1e18)
                pq.push({dist[i][j], j});
        vector<ll> vi;
        for (auto j: row[i]) vi.push_back(j);
        while (!pq.empty())
        {
            auto [W, u]=pq.top(); pq.pop();  
            if (W>dist[i][u]) continue;
            ll pos=lower_bound(vi.begin(), vi.end(), u)-vi.begin();
            if (pos>0)
            {
                ll left=vi[pos-1];
                ll cost=abs(vi[pos]-left)*x[i];
                if (dist[i][u]+cost<dist[i][left])
                {
                    dist[i][left]=dist[i][u]+cost;
                    pq.push({dist[i][left], left});
                }
            }
            if (pos<vi.size()-1)
            {
                ll right=vi[pos+1];
                ll cost=abs(right-vi[pos])*x[i];
                if (dist[i][u]+cost<dist[i][right])
                {
                    dist[i][right]=dist[i][u]+cost;
                    pq.push({dist[i][right], right});
                }
            }
        }
        for (auto j: adj[i])
            if (dist[j.a][j.b]<1e18) 
                dist[j.c][j.d]=min(dist[j.c][j.d], dist[j.a][j.b]-j.h);
    }

    if (dist[n][m]==1e18) cout<<"NO ESCAPE\n";
    else cout<<dist[n][m]<<endl;
    for (ll i=1; i<=n; i++)
    {
        row[i].clear();
        adj[i].clear();
        dist[i].clear();
    }
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