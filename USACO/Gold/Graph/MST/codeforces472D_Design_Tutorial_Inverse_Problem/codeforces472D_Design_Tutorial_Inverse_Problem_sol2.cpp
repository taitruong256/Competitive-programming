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
ll n, a[2005][2005], d[2005], p[2005];
vector<pair<ll, ll>> adj[2005], adj2[2005];
bool ans=true;

void dfs(ll u, ll par, ll src, ll dist)
{
    if (a[src][u]!=dist) ans=false;
    for (auto [v, w]: adj2[u]) if (v!=par)
        dfs(v, u, src, dist+w);
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) cin>>a[i][j];

    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++)
        {
            if (i==j && a[i][j]!=0) {cout<<"NO"; return;};
            if (i!=j && a[i][j]==0) {cout<<"NO"; return;}
            if (a[i][j]!=a[j][i]) {cout<<"NO"; return;};
            if (i<j) 
            {
                adj[i].push_back({j, a[i][j]});
                adj[j].push_back({i, a[i][j]});
            }
        }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<bool> vis(n+5, false);
    for (ll i=1; i<=n; i++) d[i]=1e18, p[i]=-1;
    d[1]=0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto [W, u]=pq.top(); pq.pop();
        if (W>d[u]) continue;
        vis[u]=true;
        for (auto [v, w]: adj[u]) if (vis[v]==false && w<d[v])
        {
            d[v]=w;
            p[v]=u;
            pq.push({d[v], v});
        }
    }
    for (ll j=2; j<=n; j++)
    {
        ll i=p[j];
        adj2[i].push_back({j, a[i][j]});
        adj2[j].push_back({i, a[i][j]});
    }
    
    for (ll i=1; i<=n; i++) dfs(i, -1, i, 0);
    if (ans==true) cout<<"YES";
    else cout<<"NO";
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