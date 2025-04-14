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
const ll inf = 1e18;
const ll mod = 1e9+7;
vector<ll> adj[200005];
ll d[200005], d1[200005], da[200005], db[200005], n, k, c;

void dfs(ll u, ll p)
{
    for (auto v: adj[u]) if (v!=p)
    {
        d[v]=d[u]+1;
        dfs(v, u);
    }
}

void solve()
{
    cin>>n>>k>>c;
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    ll root=1;
    dfs(root, 0);
    for (ll i=1; i<=n; i++) d1[i]=d[i];
    for (ll i=1; i<=n; i++) d[i]=0;


    ll a=1;
    for (ll i=1; i<=n; i++) if (d[i]>d[a]) a=i;
    dfs(a, 0);
    for (ll i=1; i<=n; i++) da[i]=d[i];
    for (ll i=1; i<=n; i++) d[i]=0;


    ll b=1;
    for (ll i=1; i<=n; i++) if (da[i]>da[b]) b=i;
    dfs(b, 0);
    for (ll i=1; i<=n; i++) db[i]=d[i];
    for (ll i=1; i<=n; i++) d[i]=0;


    ll ans=0;
    for (ll i=1; i<=n; i++) ans=max(ans, max(da[i], db[i])*k-d1[i]*c);
    cout<<ans<<endl;
    for (ll i=1; i<=n; i++) adj[i].clear();
    for (ll i=1; i<=n; i++) d[i]=0;
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