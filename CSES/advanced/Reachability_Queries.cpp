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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
ll n, m, q;
vector<ll> adj[50005], adj2[50005], scc[50005];
bool vis[50005];
bitset<50005> dp[50005];
vector<ll> topo;
ll component[50005], cnt;

void dfs(ll u)
{                
    vis[u]=true;
    for (auto v: adj[u]) if (vis[v]==false) dfs(v);
    topo.push_back(u);
}

void dfs2(ll u)
{
    component[u]=cnt;
    for (auto v: adj2[u]) if (component[v]==0) dfs2(v);
}

void dfs3(ll u)
{       
    vis[u]=true;
    dp[u].set(u, 1);
    for (auto v: scc[u])
    {
        if (vis[v]==false) dfs3(v);
        dp[u]|=dp[v];
    }
}

void solve()
{
    cin>>n>>m>>q;
    for (ll i=1; i<=m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj2[v].push_back(u);
    }
    
    //tim thanh phan lien thong manh
    for (ll i=1; i<=n; i++) if (vis[i]==false) dfs(i);
    reverse(topo.begin(), topo.end());
    for (auto i: topo) if (component[i]==0)
    {
        ++cnt;
        dfs2(i);
    }

    //ket noi cac thanh phan lien thong manh
    for (ll i=1; i<=n; i++)
        for (auto j: adj[i])
        {
            ll u=component[i];
            ll v=component[j];
            if (u!=v) scc[u].push_back(v);
        }

    //dp
    for (ll i=1; i<=cnt; i++) vis[i]=false;
    for (ll i=1; i<=cnt; i++) if (vis[i]==false) dfs3(i);

    for (ll i=1; i<=q; i++)
    {
        ll u, v; cin>>u>>v;
        ll x=component[u], y=component[v];
        if (dp[x][y]==1) cout<<"YES\n";
        else cout<<"NO\n";
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
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}