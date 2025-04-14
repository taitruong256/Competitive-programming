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
ll n, m, st=-1, fi=-1;
bool circle=false;
vector<ll> visited;
map<ll, vector<ll>> adj;
vector<ll> parent;

void dfs(ll u)
{
    visited[u]=1;
    for (auto v: adj[u])
        if (visited[v]==0) 
        {
            parent[v]=u;
            dfs(v);
            if (st!=-1) return;
        }
        else if (visited[v]==1) 
        {
            st=v;
            fi=u;
            return;
        }
    visited[u]=2;
}

void solve()
{
    cin>>n>>m;
    visited.resize(0); visited.resize(n+5, 0);
    parent.resize(0); parent.resize(n+5, 0);
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
    }


    for (ll i=1; i<=n; i++) if (visited[i]==0 && st==-1) dfs(i);   
    if (st==-1)
    {
        cout<<"IMPOSSIBLE";
        return;
    }                            // cout<<st<<" "<<fi<<endl;
    vector<ll> path;
    ll tam=fi;
    path.push_back(fi);
    while (tam!=st)
    {
        path.push_back(parent[tam]);                   
        tam=parent[tam];
    }
    reverse(path.begin(), path.end());
    path.push_back(path.front());
    cout<<path.size()<<endl;
    for (auto it: path) cout<<it<<" "; 
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