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
map<ll, vector<ll>> adj, sz;
vector<bool> visited;
vector<ll> team[100];
ll n, m, cnt;

void dfs(ll u, ll index)
{
    visited[u]=true;
    ++cnt;
    team[index].push_back(u);
    for (auto v: adj[u]) if (visited[v]==false) dfs(v, index);
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

    visited.resize(0); visited.resize(n+5, false);
    ll index=0;
    for (ll i=1; i<=n; i++) if (visited[i]==false)
    {
        ++index;
        cnt=0;
        dfs(i, index);
        if (cnt>3)
        {
            cout<<-1;
            exit(0);
        }
        sz[cnt].push_back(index);
    }

    if (sz[2].size()>sz[1].size())
    {
        cout<<-1;
        return;
    }
    for (ll i=0; i<sz[3].size(); i++)
    {
        ll x=sz[3][i];
        cout<<team[x][0]<<" "<<team[x][1]<<" "<<team[x][2]<<endl;
    }
    for (ll i=0; i<sz[2].size(); i++)
    {
        ll x=sz[2][i];
        ll y=sz[1][i];
        cout<<team[x][0]<<" "<<team[x][1]<<" "<<team[y][0]<<endl;
    }
    for (ll i=sz[2].size(); i<sz[1].size(); i+=3)
    {
        ll x=sz[1][i];
        ll y=sz[1][i+1];
        ll z=sz[1][i+2];
        cout<<team[x][0]<<" "<<team[y][0]<<" "<<team[z][0]<<endl;
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