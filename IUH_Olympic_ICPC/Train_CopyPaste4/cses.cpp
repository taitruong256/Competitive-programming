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
const ll maxn = 2e5+5;
ll n, m;
vector<ll> adj[maxn];
vector<ll> d, in, parent, ans;
vector<bool> visited;
 
void solve()
{
    cin>>n>>m;
    in.resize(0); in.resize(n+5, 0);
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        ++in[v];
    }
 
    d.resize(0); d.resize(n+5, -1); d[1]=0;
    parent.resize(0); parent.resize(n+5, 0);
    queue<ll> q;
    q.push(1);
    while (!q.empty())
    {
        ll u=q.front(); q.pop();
        for (auto v: adj[u])
        {
            if (d[u]!=-1 && d[u]+1>d[v])
            {
                d[v]=d[u]+1;
                parent[v]=u;
            }
            --in[v];
            if (in[v]==0) q.push(v);
        }
    }

    if (d[n]==-1)
    {
        cout<<"IMPOSSIBLE";
        return;
    }
 
    ll t=n;
    while (t!=0)
    {
        ans.push_back(t);
        t=parent[t];
    }
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for (auto it: ans) cout<<it<<" "; cout<<endl;
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