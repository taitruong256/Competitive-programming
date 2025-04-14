/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const ll mod = 1e9+7;
const ll inf = 1e9;
ll n, q; 
ll parent[200005][21], level[200005];
map<ll, vector<ll>> adj;

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

void solve()
{
    cin>>n>>q;
    memset(parent, 0, sizeof(parent));
    memset(level, -1, sizeof(level));
    for (ll i=2; i<=n; i++) 
    {
        cin>>parent[i][0];
        ll u=parent[i][0];   
        adj[u].push_back(i);
        adj[i].push_back(u);
    } 

    for (ll j=1; j<21; j++)
        for (ll i=1; i<=n; i++) parent[i][j]=parent[parent[i][j-1]][j-1];
    
    bfs(1);
    while (q--)
    {
        ll u, v; cin>>u>>v;
        cout<<query(u, v)<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}