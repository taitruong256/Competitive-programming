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
ll n, m, cap[505][505];
vector<pair<ll, ll>> adj[505];
vector<ll> adj2[505], par;
vector<ll> vis, path;

ll bfs(ll s, ll t)
{
    par.assign(n+5, 0);
    queue<pair<ll, ll>> q;
    q.push({s, 1e18});
    par[s]=-1;
    while (!q.empty())
    {
        ll u=q.front().first;         
        ll w=q.front().second;
        if (u==t) return w;
        q.pop();
        for (auto v: adj2[u]) if (par[v]==0 && cap[u][v]>0)
        {
            par[v]=u;
            q.push({v, min(w, cap[u][v])});
        }
    }
    return 0;
}

ll max_flow(ll s, ll t)
{
    ll flow=0;
    while (true)
    {
        ll f=bfs(1, n);    
        if (f==0) break;
        flow+=f;
        ll v=t;
        while (v!=s)
        {      
            ll u=par[v];
            cap[u][v]-=f;
            cap[v][u]+=f;
            v=u;
        }        
    }
    return flow;
}

void dfs(ll u)
{
    path.push_back(u);
    for (auto [v, i]: adj[u]) if (vis[i]==false && cap[u][v]==0)
    {
        vis[i]=true;
        dfs(v);
        return;
    }
}

void solve()
{
    cin>>n>>m;
    for (ll i=0; i<m; i++) 
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back({v, i});
        adj2[u].push_back(v);
        adj2[v].push_back(u);
        cap[u][v]+=1;
    }

    ll k=max_flow(1, n);
    cout<<k<<endl;
    vis.assign(m+5, false);
    for (ll i=0; i<k; i++)
    {
        path.clear();
        dfs(1);
        cout<<path.size()<<endl;
        for (auto x: path) cout<<x<<" "; 
        cout<<endl;
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