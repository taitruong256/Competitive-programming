/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, vector<ll>> ke;
vector<ll> color;

void bfs(ll u)
{
    queue<ll> q;
    q.push(u);
    color[u]=0;   
    while (!q.empty())
    {
        
    }
}

void solve()
{
    ll n, m; cin>>n>>m;
    color.resize(0);
    color.resize(n+5, -1);
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    for (ll i=1; i<=n; i++) if (color[i]==-1) bfs(i);
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