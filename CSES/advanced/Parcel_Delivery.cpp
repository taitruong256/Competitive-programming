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

struct Edge
{
    ll from, to, capacity, cost;

    Edge(){}
    Edge(ll _from, ll _to, ll _capacity, ll _cost)
    {
        from=_from;
        to=_to;
        capacity=_capacity;
        cost=_cost;
    }
};

vector<ll> adj[1005];
Edge edges[1005], redges[1005];
ll cost[1005][1005], capacity[1005][1005], par[1005], d[1005];
ll n, m, k;

void shortest_path()
{
    vector<bool> vis(n+5, false);
    for (ll i=1; i<=n; i++) d[i]=inf;
    for (ll i=1; i<=n; i++) par[i]=-1;
    queue<ll> q;
    d[1]=0;
    q.push(1);
    vis[1]=true;

    while (!q.empty())
    {
        ll u=q.front(); q.pop();
        vis[u]=false;
        for (auto i: adj[u])
        {
            Edge e=i<0?redges[-i]:edges[i];
            if (e.capacity>0 && d[e.from]+e.cost<d[e.to])
            {
                d[e.to]=d[e.from]+e.cost;
                par[e.to]=i;
                if (vis[e.to]==false)
                {
                    vis[e.to]=true;
                    q.push(e.to);
                }
            }
        }
    }
}

ll max_flow_min_cost()
{
    ll flow=0, cost=0;
    while (flow<k)
    {
        shortest_path();
        if (d[n]==inf) break;
        ll f=k-flow;
        ll v=n;
        while (v!=1)
        {
            Edge e=(par[v]<0)?redges[-par[v]]:edges[par[v]];
            f=min(f, e.capacity);
            v=e.from;
        }
        flow+=f;
        cost+=f*d[n];
        v=n;
        while (v!=1)
        {
            if (par[v]<0)
            {
                redges[-par[v]].capacity-=f;
                edges[-par[v]].capacity+=f;
            }
            else 
            {
                edges[par[v]].capacity-=f;
                redges[par[v]].capacity+=f;
            }
            if (par[v]<0) v=redges[-par[v]].from;
            else v=edges[par[v]].from;
        }
    }
    if (flow<k) return -1;
    return cost;
}

void solve()
{
    cin>>n>>m>>k;
    for (ll i=1; i<=m; i++)
    {
        ll u, v, w, c; cin>>u>>v>>w>>c;
        adj[u].push_back(i);
        adj[v].push_back(-i);
        edges[i]=Edge(u, v, w, c);
        redges[i]=Edge(v, u, 0, -c);
    }
    cout<<max_flow_min_cost();
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