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
#define endl '\n'
#define ll long long
const ll mod = 1e9+7;
const ll inf = 1e9;
ll n, root;
ll parent[200005][21], level[200005], c[200005], ans[200005];
vector<ll> adj[200005];
 
void bfs(ll s)
{
    queue<ll> q;
    q.push(s);
    level[s]=0;
    while (!q.empty())
    {
        ll u=q.front(); q.pop();
        for (auto v: adj[u]) if (level[v]==-1)
        {
            q.push(v);
            level[v]=level[u]+1;
            parent[v][0]=u;
        }
    }
}
 
ll query(ll x, ll y)
{
    if (level[x]<level[y]) swap(x, y);
    ll d=level[x]-level[y];
    for (ll i=0; i<21; i++) if (d&(1<<i)) x=parent[x][i];
    if (x==y) return x;
    for (ll i=20; i>=0; i--) if (parent[x][i]!=parent[y][i])
    {
        x=parent[x][i];
        y=parent[y][i];
    }
    return parent[x][0];
}

ll distance(ll u, ll v)
{
    ll lcm=query(u, v);
    return level[u]+level[v]-2*level[lcm];
}
 
void solve()
{
    cin>>n>>root;
    for (ll i=1; i<=n; i++) level[i]=-1;
    for (ll i=1; i<=n-1; i++) cin>>c[i];
    for (ll i=1; i<=n-1; i++) 
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } 
    bfs(root);
    for (ll j=1; j<21; j++)
        for (ll i=1; i<=n; i++) parent[i][j]=parent[parent[i][j-1]][j-1];

    ans[1]=distance(root, c[1]);
    ll x=root, y=c[1];
    for (ll i=2; i<=n-1; i++)
    {
        ll z=c[i];
        ll t1=distance(x, y);
        ll t2=distance(x, z);
        ll t3=distance(y, z);
        if (t2<=t1 && t2<=t3) y=z;
        else if (t3<=t1 && t3<=t2) x=z;  cout<<x<<" "<<y<<endl;
        ans[i]=distance(x, y);
    }
    for (ll i=1; i<=n-1; i++) cout<<ans[i]<<" ";
    cout<<endl;
    for (ll i=1; i<=n; i++) adj[i].clear();
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}