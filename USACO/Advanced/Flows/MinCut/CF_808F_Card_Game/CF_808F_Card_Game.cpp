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

struct Dinic
{
    struct Edge {ll u, v, flow, cap;};
    ll n, m=0, s, t, inf=1e18;
    vector<vector<ll>> adj;
    vector<Edge> edge;
    vector<ll> level, ptr;
    Dinic(){}
    Dinic(ll _n, ll _s, ll _t)
    {
        n=_n;
        s=_s;
        t=_t;
        adj.resize(n+5);
        ptr.resize(n+5);
        level.resize(n+5);
    }

    void add_edge(ll u, ll v, ll cap)
    {
        adj[u].push_back(m);
        adj[v].push_back(m+1);
        edge.push_back({u, v, 0, cap});
        edge.push_back({v, u, 0, 0});   //neu 1 chieu thi edge.push_back({v, u, 0, 0});
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

    vector<pair<ll, ll>> minCut()
    {
        vector<pair<ll, ll>> ans;
        maxFlow();
        bfs();
        for (auto [u, v, f, c]: edge) if (level[u]!=-1 && level[v]==-1) ans.push_back({u, v});
        return ans;
    }
};

struct Sieve
{
    ll n;
    vector<bool> prime;
    Sieve(){}
    Sieve(ll _n)
    {
        n=_n;
        prime.resize(n+5);
        fill(prime.begin(), prime.end(), true);
        prime[0]=prime[1]=false;
        for (ll i=2; i*i<=n; i++) if (prime[i]==true)
            for (ll j=i*i; j<=n; j+=i) prime[j]=false;
    }
};
Sieve sieve(2e5);

ll n, k, p[105], c[105], l[105];

bool check(ll x)
{
    ll mx=0, id=-1, sum=0;
    Dinic dinic(n+2, 0, n+1);
    for (ll i=1; i<=n; i++) if (l[i]<=x)
    {
        if (c[i]==1)
        {
            if (p[i]>mx) mx=p[i], id=i;
        }
        else 
        {
            sum+=p[i];
            if (c[i]%2==1) dinic.add_edge(0, i, p[i]);
            else dinic.add_edge(i, n+1, p[i]);
        }
    }
    if (id!=-1)
    {
        sum+=mx;
        dinic.add_edge(0, id, mx);
    }
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) 
            if (l[i]<=x && l[j]<=x && i!=j && sieve.prime[c[i]+c[j]]==true && c[i]%2==1) 
                dinic.add_edge(i, j, 1e18);
    ll mf=dinic.maxFlow();                        cout<<sum<<" "<<mf<<endl;
    if (sum-mf>=k) return true;
    return false;
}

void solve()
{
    cin>>n>>k;
    for (ll i=1; i<=n; i++) cin>>p[i]>>c[i]>>l[i];
    ll l=1, r=k, ans=-1;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (check(mid)==true) ans=mid, r=mid-1;
        else l=mid+1;
    }
    cout<<ans;
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