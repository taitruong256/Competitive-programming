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
vector<bool> visited;
map<ll, vector<ll>> adj;
vector<ll> parent;

// bool dfs(ll u, ll p)
// {      cout<<u<<" "<<p<<endl;
//     visited[u]=true;
//     parent[u]=p;
//     for (auto v: adj[u])
//     {
//         if (visited[v]==false)
//             if (dfs(v, u)==true) 
//                 return true;
//         else if (v!=p) 
//         {
//             st=u;
//             fi=v;
//             return true;
//         }
//     }
//     return false;
// }

void dfs(ll u, ll p)
{
    visited[u]=true;
    for (auto v: adj[u])
        if (visited[v]==false) 
        {
            parent[v]=u;
            dfs(v, u);
        }
        else if (v!=p) 
        {
            st=u;
            fi=v;
        }
}

void solve()
{
    cin>>n>>m;
    visited.resize(0); visited.resize(n+5, false);
    parent.resize(0); parent.resize(n+5, 0);
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (ll i=1; i<=n; i++) if (visited[i]==false) dfs(i, 0);   
    // for (ll i=1; i<=n; i++) cout<<parent[i]<<" "; cout<<endl;
    // cout<<st<<" "<<fi<<endl;
    if (st==-1 && fi==-1)
    {
        cout<<"IMPOSSIBLE";
        return;
    }
    vector<ll> path;
    ll tam=fi;
    path.push_back(fi);
    while (tam!=st)
    {
        path.push_back(parent[tam]);                   
        tam=parent[tam];
    }
    path.push_back(fi);
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