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
ll n, m; 
map<ll, vector<ll>> adj;
vector<ll> color;
bool circle=false;

bool bfs(ll u)
{
    queue<ll> q;
    q.push(u);
    color[u]=1;
    while (!q.empty())
    {
        ll x=q.front(); q.pop();    //cout<<x<<endl;
        for (auto v: adj[x]) 
            if (color[v]==-1)
            {  
                q.push(v);
                color[v]=3-color[x];
            }
            else if (color[x]==color[v]) return false;
    }
    return true;
}

void solve()
{
    cin>>n>>m;
    color.resize(0); color.resize(n+5, -1);
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ok=true;
    for (ll i=1; i<=n; i++) if (color[i]==-1) ok&=bfs(i);
    if (ok) for (ll i=1; i<=n; i++) cout<<color[i]<<" ";
    else cout<<"IMPOSSIBLE";
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