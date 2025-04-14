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
ll n, q, par[200005], succ[200005][25], depth[200005];
vector<ll> adj[200005];
vector<bool> vis;

void dfs(ll u)
{
    vis[u]=true;
    ll v=succ[u][0];
    if (vis[v]==false) dfs(v);
    depth[u]=depth[v]+1;
}

ll lift(ll u, ll k)
{
    if (k<=0) return u;
    for (ll i=0; i<=20; i++) if (k&(1<<i)) u=succ[u][i];
    return u;
}

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>succ[i][0];
    for (ll i=1; i<=20; i++)
        for (ll p=1; p<=n; p++) succ[p][i]=succ[succ[p][i-1]][i-1];

    vis.assign(n+5, false);
    for (ll i=1; i<=n; i++) if (vis[i]==false) dfs(i);

    for (ll i=0; i<q; i++)
    {
        ll u, v; cin>>u>>v;
        ll t=lift(u, depth[u]);
        if (lift(u, depth[u]-depth[v])==v) cout<<depth[u]-depth[v]<<endl;
        else if (lift(t, depth[t]-depth[v])==v) cout<<depth[u]+depth[t]-depth[v]<<endl;
        else cout<<-1<<endl;
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