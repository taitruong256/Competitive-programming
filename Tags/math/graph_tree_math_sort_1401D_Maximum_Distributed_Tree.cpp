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
ll n, m, sub[200005];
vector<ll> adj[200005];
deque<ll> edges, p;
bool vis[200005];

void dfs(ll u)
{
    vis[u]=true;
    sub[u]=1;
    for (auto v: adj[u]) if (vis[v]==false)
    {
        dfs(v);
        sub[u]+=sub[v];
    }
    if (u!=1) edges.push_back(sub[u]*(n-sub[u]));
}

void solve()
{
    cin>>n;
    for (ll i=0; i<n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin>>m;
    for (ll i=0; i<m; i++) 
    {
        ll x; cin>>x;
        p.push_back(x);
    }
    dfs(1);
    sort(p.begin(), p.end(), greater<ll>());
    sort(edges.begin(), edges.end(), greater<ll>());
    
    if (m<=n-1)
        while (p.size()<n-1) p.push_back(1);
    else 
        while (p.size()>n-1)
        {
            ll x=p.front(); p.pop_front();
            p.front()=(p.front()*x)%mod;
        }

    ll ans=0;
    for (ll i=0; i<n-1; i++) ans=(ans+p[i]*edges[i])%mod;
    cout<<ans<<endl;
    p.clear();
    edges.clear();
    for (ll i=1; i<=n; i++) adj[i].clear();
    for (ll i=1; i<=n; i++) vis[i]=false;
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