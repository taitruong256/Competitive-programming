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
ll n, a, b; 
vector<ll> d1, da, db;
map<ll, vector<ll>> adj;

void bfs(ll s, vector<ll> &d)
{
    d.resize(0); d.resize(n+5, -1);

    d[s]=0;
    queue<ll> q;
    q.push(s);
    while (!q.empty())
    {
        ll u=q.front(); q.pop();  
        for (auto v: adj[u]) if (d[v]==-1)
        {
            d[v]=d[u]+1;
            q.push(v);
        }
    }
}

void solve()
{
    cin>>n;  
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1, d1);
    a=1;
    for (ll i=1; i<=n; i++) if (d1[i]>d1[a]) a=i; 
    bfs(a, da);
    b=1;
    for (ll i=1; i<=n; i++) if (da[i]>da[b]) b=i;

    bfs(b, db);         
    for (ll i=1; i<=n; i++) cout<<max(da[i], db[i])<<" ";
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