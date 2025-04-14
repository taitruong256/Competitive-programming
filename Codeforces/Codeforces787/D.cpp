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
map<ll, vector<ll>> adj, adj2, path;
vector<ll> visited, topo;
ll n, cnt;

void dfs(ll u)
{                  // cout<<u<<" ";
    visited[u]=1;
    path[cnt].push_back(u);
    for (auto v: adj[u]) if (visited[v]==0)
    {
        if (adj[v].size()==1) 
        {
            path[cnt].push_back(v);
            visited[v]=1;
            return;
        }
        else dfs(v);
        break;
    }
}

void sptopo(ll u)
{                
    visited[u]=1;
    for (auto v: adj[u]) if (visited[v]==0) sptopo(v);
    topo.push_back(u);
}


void solve()
{
    cin>>n;  
    visited.resize(0); visited.resize(n+5, 0);
    adj.clear();
    adj2.clear();
    topo.clear();
    path.clear();
    ll root=1;
    for (ll i=1; i<=n; i++)
    {
        ll x; cin>>x;  
        if (x==i) root=i;
        else adj[x].push_back(i), adj[i].push_back(x);
    }       

    // for (auto i: adj)
    // {
    //     for (auto j: i.second) cout<<j<<" "; cout<<endl;
    // }cout<<endl;

    sptopo(root);
    reverse(topo.begin(), topo.end());
    // for (auto v: topo) cout<<v<<" "; cout<<endl;
    cnt=0;
    visited.resize(0); visited.resize(n+5, 0);
    for (auto v: topo) if (visited[v]==false)
    {
        ++cnt;
        dfs(v);
    }
    cout<<cnt<<endl;
    for (ll i=1; i<=cnt; i++)
    {
        cout<<path[i].size()<<endl;
        for (ll j=0; j<path[i].size(); j++) cout<<path[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
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