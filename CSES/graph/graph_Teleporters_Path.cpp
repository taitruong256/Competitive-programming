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
vector<ll> adj[100005];
vector<bool> visited;
vector<ll> path, in;

void dfs(ll u)
{            
    visited[u]=true;
    for (auto v: adj[u]) if (visited[v]==false) dfs(v);
}

void euler_cycle(ll s)
{
    stack<ll> st;
    st.push(s);
    while (!st.empty())
    {
        ll x=st.top();
        if (adj[x].size()!=0)
        {
            ll y=adj[x].back();
            adj[x].pop_back();
            st.push(y);
        }
        else
        {
            path.push_back(x);
            st.pop();
        }
    }
    reverse(path.begin(), path.end());
}

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

    visited.resize(0); visited.resize(n+5, false);
    dfs(1);
    bool exist=true;
    if (visited[n]==false) exist=false;
    if (adj[1].size()-in[1]!=1) exist=false;
    if (adj[n].size()-in[n]!=-1) exist=false;
    for (ll i=2; i<=n-1; i++)
    {
        if (adj[i].size()!=in[i]) exist=false;
        if (visited[i]==false && (adj[i].size()!=0 || in[i]!=0)) exist=false;
    }

    if (exist==false)
    {
        cout<<"IMPOSSIBLE";
        return;
    }
    else 
    {
        euler_cycle(1);
        for (auto it: path) cout<<it<<" ";
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