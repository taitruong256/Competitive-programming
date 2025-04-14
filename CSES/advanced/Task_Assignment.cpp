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

vector<ll> adj[2005];
Edge edges[40405], redges[40405];
ll cost[2005][2005], capacity[2005][2005], par[2005], d[2005];
ll n;

void shortest_path()
{
    vector<bool> vis(2*n+5, false);
    for (ll i=0; i<=2*n+1; i++) d[i]=inf;
    for (ll i=0; i<=2*n+1; i++) par[i]=-1;
    queue<ll> q;
    d[0]=0;
    q.push(0);
    vis[0]=true;

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
    while (flow<n)
    {
        shortest_path();
        if (d[2*n+1]==inf) break;
        ll f=n-flow;
        ll v=2*n+1;
        while (v!=0)
        {
            Edge e=(par[v]<0)?redges[-par[v]]:edges[par[v]];
            f=min(f, e.capacity);
            v=e.from;
        }
        flow+=f;
        cost+=f*d[2*n+1];
        v=2*n+1;
        while (v!=0)
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
    if (flow<n) return -1;
    return cost;
}

void solve()
{
    cin>>n;
    ll edgeID=1;
    for (ll u=1; u<=n; u++)
    {
        for (ll v=n+1; v<=2*n; v++)
        {
            ll c; cin>>c;
            adj[u].push_back(edgeID);
            adj[v].push_back(-edgeID);
            edges[edgeID]=Edge(u, v, 1, c);
            redges[edgeID]=Edge(v, u, 0, -c);
            edgeID++;
        }
    }

    for (ll v=1; v<=n; v++)
    {
        adj[0].push_back(edgeID);
        adj[v].push_back(-edgeID);
        edges[edgeID]=Edge(0, v, 1, 0);
        redges[edgeID]=Edge(v, 0, 0, 0);
        edgeID++;
    }

    for (ll u=n+1; u<=2*n; u++)
    {               
        adj[u].push_back(edgeID);
        adj[2*n+1].push_back(-edgeID);
        edges[edgeID]=Edge(u, 2*n+1, 1, 0);
        redges[edgeID]=Edge(2*n+1, u, 0, 0);
        edgeID++;
    }
    cout<<max_flow_min_cost()<<endl;
    vector<bool> vis(2*n+5, false);
    for (ll u=1; u<=n; u++)
    {
        for (auto i: adj[u]) if (edges[i].capacity==0) 
        {
            ll v=edges[i].to-n;
            cout<<u<<" "<<v<<endl;
            break;
        }
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