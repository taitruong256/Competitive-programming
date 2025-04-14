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
ll n, m, p[200005], h[200005], tp[200005];
vector<ll> adj[200005];
bool vis[200005], check=true;

void dfs(ll u)
{
    vis[u]=true;
    tp[u]=0;
    for (auto v: adj[u]) if (vis[v]==false)
    {
        dfs(v);
        p[u]+=p[v];
        tp[u]+=tp[v];
    }
    if ((p[u]+h[u])%2!=0) check=false;
    ll x=(p[u]+h[u])/2;
    if (tp[u]>x) check=false;
    tp[u]=x;
    if (!(0<=x && x<=p[u])) check=false;         
}

void solve()
{
    cin>>n>>m;
    check=true;
    for (ll i=1; i<=n; i++) cin>>p[i];
    for (ll i=1; i<=n; i++) cin>>h[i];
    for (ll i=0; i<n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    if (check==true) cout<<"YES\n";
    else cout<<"NO\n";
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