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
map<ll, vector<ll>> adj;
vector<ll> color;
ll n, m;

bool bfs(ll u)
{
    queue<ll> q;
    q.push(u);
    color[u]=0;
    while (!q.empty())
    {
        ll v=q.front(); q.pop(); 
        for (auto x: adj[v]) 
            if (color[x]==-1)
            {
                color[x]=1-color[v];
                q.push(x);
            }
            else if (color[x]==color[v]) return false;
    }
    return true;
}

void solve()
{
    cin>>n>>m;
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    color.resize(0);
    color.resize(n+5, -1);
    for (ll i=1; i<=n; i++) if (color[i]==-1)
    {
        // if (adj[i].empty()) continue;
        if (bfs(i)==false) 
        {
            cout<<-1;
            return;
        }
    }
    for (ll i=0; i<2; i++)
    {
        vector<ll> v;
        v.clear();
        for (ll j=1; j<=n; j++) if (color[j]==i) v.push_back(j);
        cout<<v.size()<<endl;
        for (auto it: v) cout<<it<<" "; cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}