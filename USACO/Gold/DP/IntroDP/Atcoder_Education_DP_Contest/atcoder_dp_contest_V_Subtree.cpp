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
ll n, mod, dp[100005], ans[100005];
vector<ll> adj[100005];

void dfs1(ll u, ll par=-1)
{
    dp[u]=1;     
    for (auto v: adj[u]) if (v!=par)
    {
        dfs1(v, u);
        dp[u]=(dp[u]*dp[v])%mod;
    }
    dp[u]=(dp[u]+1)%mod;    
}

void dfs2(ll u, ll par=-1)
{
    ans[u]=dp[u];
    ll m=adj[u].size();
    vector<ll> pref(m+5, 1), suff(m+5, 1);
    for (ll i=0; i<m; i++) pref[i+1]=(pref[i]*dp[adj[u][i]])%mod;
    for (ll i=m-1; i>=0; i--) suff[i+1]=(suff[i+2]*dp[adj[u][i]])%mod;
    for (ll i=0; i<m; i++) if (adj[u][i]!=par)
    {
        dp[u]=((pref[i]*suff[i+2])%mod+1)%mod;
        dp[adj[u][i]]=(dp[adj[u][i]]-1+mod)%mod*dp[u]%mod;
        dfs2(adj[u][i], u);
    }
}

void solve()
{
    cin>>n>>mod;       
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1);
    dp[1]=(dp[1]-1+mod)%mod;
    dfs2(1);
    for (ll i=1; i<=n; i++) cout<<ans[i]<<endl;
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