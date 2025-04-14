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
                                       Where is the bug, delete it there
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e18;

struct MinCostMaxFlow
{
    //tim luong toi da la k co chi phi nho nhat
    struct Edge {ll u, v, flow, cap, cost;};
    ll n, m=0, k, s, t;
    vector<vector<ll>> adj;
    vector<Edge> edge;
    vector<ll> dist, par;
    vector<bool> inq;

    MinCostMaxFlow(){}
    MinCostMaxFlow(ll _n, ll _k, ll _s, ll _t)
    {
        n=_n; k=_k; s=_s; t=_t;
        adj.resize(n+5);
        dist.resize(n+5);
        par.resize(n+5);
        inq.resize(n+5);
    }

    void addEdge(ll u, ll v, ll cap, ll cost)
    {
        edge.push_back({u, v, 0, cap, cost});
        edge.push_back({v, u, 0, 0 , -cost}); //mot chieu
        adj[u].push_back(m);
        adj[v].push_back(m+1);
        m+=2;
    }

    bool SPFA()
    {
        fill(dist.begin(), dist.end(), inf);
        fill(par.begin(), par.end(), -1);
        fill(inq.begin(), inq.end(), false);
        queue<ll> q;
        q.push(s);
        dist[s]=0;
        inq[s]=true;
        while (!q.empty())
        {
            ll u=q.front();
            q.pop();
            inq[u]=false;
            for (ll id: adj[u])
            {
                Edge e=edge[id];
                if (e.flow<e.cap && dist[e.u]+e.cost<dist[e.v])
                {
                    dist[e.v]=dist[e.u]+e.cost;
                    par[e.v]=id;
                    if (inq[e.v]==false)
                    {
                        inq[e.v]=true;
                        q.push(e.v);
                    }
                }
            }
        }
        return dist[t]!=inf;
    }

    bool Dijktra()
    {
        fill(dist.begin(), dist.end(), inf);
        fill(par.begin(), par.end(), -1);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        dist[s]=0;
        pq.push({0, s});
        while (!pq.empty())
        {
            auto [wu, u]=pq.top(); 
            pq.pop();
            if (wu>dist[u]) continue;
            for (ll id: adj[u]) 
            {
                Edge e=edge[id];
                if (e.flow<e.cap && dist[e.u]+e.cost<dist[e.v])
                {
                    dist[e.v]=dist[e.u]+e.cost;
                    pq.push({dist[e.v], e.v});
                    par[e.v]=id;
                }
            }   
        }
        return dist[t]!=inf;
    }

    pair<ll, ll> minCost()
    {
        ll totFlow=0, totCost=0;
        while (totFlow<k)
        {
            if (SPFA()==false) break;
            ll f=k-totFlow;
            ll v=t;
            while (v!=s)
            {
                f=min(f, edge[par[v]].cap-edge[par[v]].flow);
                v=edge[par[v]].u;
            }
            totFlow+=f;
            totCost+=f*dist[t];
            v=t;
            while (v!=s)
            {
                edge[par[v]].flow+=f;
                edge[par[v]^1].flow-=f;
                v=edge[par[v]].u;
            }
        }
        if (totFlow<k) totCost=-1; //neu luong cuc dai <k tra ve {totFlow, -1}
        return {totFlow, totCost};
    }
}; 
ll n, a[3005], m[10], lst[100005];

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    MinCostMaxFlow mcmf(2*n+2, 4, 0, 2*n+1);
    for (ll i=1; i<=n; i++)
    {
        mcmf.addEdge(i, i+n, 1, -1);
        mcmf.addEdge(0, i, 1, 0);
        mcmf.addEdge(i+n, 2*n+1, 1, 0);
        if (m[a[i]%7]!=0) mcmf.addEdge(m[a[i]%7]+n, i, 1, 0);
        if (lst[a[i]-1]!=0) mcmf.addEdge(lst[a[i]-1]+n, i, 1, 0);
        if (lst[a[i]+1]!=0) mcmf.addEdge(lst[a[i]+1]+n, i, 1, 0);
        m[a[i]%7]=i;
        lst[a[i]]=i;
    }
    cout<<-mcmf.minCost().second;
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