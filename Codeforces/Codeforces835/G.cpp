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
                             Nothing is impossible, only you think it is impossible                 
                                     Try, try, try again until you succeed     
                                        Pratice, practice, and practice
                                       Where is your bug, delete it there
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
ll n, a, b; 
vector<pair<ll, ll>> adj[100005];
vector<bool> vis;
vector<ll> xra, xrb;
map<ll, ll> cnt;

void dfs_a(ll u, ll x)
{
    xra[u]=x;
    vis[u]=true;
    for (auto [v, w]: adj[u]) if (vis[v]==false) dfs_a(v, x^w);
}

void dfs_b(ll u, ll x)
{
    xrb[u]=x;
    vis[u]=true;
    for (auto [v, w]: adj[u]) if (vis[v]==false) dfs_b(v, x^w);
}

void solve()
{
    cin>>n>>a>>b;
    vis.clear();
    xra.clear();
    xrb.clear();
    cnt.clear();
    vis.resize(n+5, false);
    xra.resize(n+5);
    xrb.resize(n+5);
    for (ll i=1; i<n; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs_a(a, 0);
    for (ll i=1; i<=n; i++) ++cnt[xra[i]];

    for (ll i=1; i<=n; i++) vis[i]=false;
    dfs_b(b, 0);
    for (ll i=1; i<=n; i++) ++cnt[xrb[i]];
    
    for (ll i=1; i<=n; i++) if (xra[i]==xrb[i] && i!=b)
    {
        cout<<"YES\n";
        return;
    }
    // for (auto i: cnt) cout<<i.first<<" "<<i.second<<endl;
    for (auto [x, v]: cnt) if (v>1)
    {
        if (x==0 && v<=2) continue; 
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
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