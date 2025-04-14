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
struct edge{ll u, v, w;};
vector<edge> E;

ll n, m, num[200005], low[200005], timeDfs, brid=0, component=0;
bool vis[200005], firstTime=true;
vector<pair<ll, ll>> adj[200005];

void Tarjan(ll u, ll p) 
{
    num[u] =low[u] = ++timeDfs;
    ll child = (p!=-1);
    for(auto [v, w]: adj[u]) 
    {
        if(v==p) continue;
        if(!num[v]) 
        {
            Tarjan(v, u);
            low[u]=min(low[u], low[v]);
            if(low[v]>num[u]) brid++;
            if(low[v]>=num[u]) child++;
        }
        else  
        {
            low[u]=min(low[u], num[v]);
        }
    }
}

void dfs(ll u, ll par, ll maxw)
{
    vis[u]=true;
    if (u==1)
    {
        if (firstTime==true) vis[u]=false; 
    }                 
    firstTime=false;
    for (auto [v, w]: adj[u]) if (vis[v]==false && w<=maxw && v!=par) dfs(v, u, maxw);
}

bool check(ll x)
{
    for (ll i=1; i<=n; i++) adj[i].clear();
    for (auto [u, v, w]: E) if (w<=x) adj[u].push_back({v, w});

    brid=0;
    Tarjan(1, 1);  
    if (brid>0) return false;

    firstTime=true;
    for (ll i=1; i<=n; i++) vis[i]=false;
    ll cnt=0;
    dfs(1, 1, x);
    for (ll i=1; i<=n; i++) if (vis[i]==false) ++cnt;
    return cnt==0;
}

void solve()
{
    cin>>n>>m;
    for (ll i=0; i<m; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        E.push_back({u, v, w});
        E.push_back({v, u, w});
    }

    for (ll i=1; i<=n; i++) vis[i]=false;
    dfs(1, 1, 1e18); 
    for (ll i=1; i<=n; i++) if (vis[i]==false) ++component;
    if (component>0) 
    {
        cout<<-1;
        return;
    }

    brid=timeDfs=0;
    Tarjan(1, 1);  
    if (brid>0)
    {
        cout<<-1;
        return;
    }

    ll l=1, r=1e9, ans=-1;
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