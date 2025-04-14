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
                                          Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;

struct Dinic
{
    struct Edge {ll u, v, flow, cap;};
    ll n, m=0, s, t, inf=1e18;
    vector<vector<ll>> adj;
    vector<Edge> edge;
    vector<ll> level, ptr;
    vector<bool> vis;

    Dinic(){}
    Dinic(ll _n, ll _s, ll _t)
    {
        n=_n;
        s=_s;
        t=_t;
        adj.resize(n+5);
        ptr.resize(n+5);
        level.resize(n+5);
        vis.resize(n+5);
    }

    void add_edge(ll u, ll v, ll cap)
    {
        adj[u].push_back(m);
        adj[v].push_back(m+1);
        edge.push_back({u, v, 0, cap});
        edge.push_back({v, u, 0, cap});   //neu 1 chieu thi edge.push_back({v, u, 0, 0});
        m+=2;
    }

    bool bfs()
    {
        fill(level.begin(), level.end(), -1);
        queue<ll> q;
        q.push(s);
        level[s]=0;
        while (!q.empty())
        {
            ll u=q.front(); q.pop(); 
            for (ll id: adj[u]) 
            {
                Edge e=edge[id];
                if (level[e.v]==-1 && e.flow<e.cap)
                {
                    q.push(e.v);
                    level[e.v]=level[u]+1;
                }
            }
        }
        return level[t]!=-1;
    }

    ll dfs(ll u, ll minCap)
    {
        if (u==t) return minCap;
        if (minCap==0) return 0;
        for (ll &id=ptr[u]; id<(ll)adj[u].size(); id++)  //them dau &id
        {
            ll idEdge=adj[u][id];
            Edge e=edge[idEdge];
            if (e.flow<e.cap && level[e.u]+1==level[e.v]) 
            {
                ll bottleneck=dfs(e.v, min(minCap, e.cap-e.flow));
                if (bottleneck>0) 
                {
                    edge[idEdge].flow+=bottleneck;
                    edge[idEdge^1].flow-=bottleneck;
                    return bottleneck;
                }
            }
        }
        return 0;
    }

    ll maxFlow()
    {
        ll totalFlow=0;
        while (true)
        {
            if (!bfs()) break;
            fill(ptr.begin(), ptr.end(), 0);
            while (ll bottleneck=dfs(s, inf)) totalFlow+=bottleneck;
        }
        return totalFlow;
    }

    void dfs2(ll u)
    {
        vis[u]=true;
        for (ll id: adj[u]) 
        {
            Edge e=edge[id];
            if (vis[e.v]==false && e.cap-e.flow>0) dfs2(e.v);
        }
    }

    vector<pair<ll, ll>> minCut()
    {
        vector<pair<ll, ll>> ans;
        maxFlow();
        fill(vis.begin(), vis.end(), false);
        dfs2(s);
        for (auto [u, v, f, c]: edge) if (vis[u]==true && vis[v]==false) ans.push_back({u, v});
        return ans;
    }
};

void solve()
{
    ll n, m; cin>>n>>m;
    Dinic dinic(n+5, 1, n);
    for (ll i=1; i<=m; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        dinic.add_edge(u, v, w);
    }
    cout<<dinic.maxFlow()<<endl;
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