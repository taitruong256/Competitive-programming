/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m; 
vector<ll> canh[100005];
bool visited[100005];

void dfs(ll u)
{
    visited[u]=true;
    for (auto v: canh[u]) if (visited[v]==false) dfs(v);
}

void solve()
{
    memset(visited, false, sizeof(false));
    cin>>n>>m;
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        canh[u].push_back(v);
        canh[v].push_back(u);
    }
    ll ans=0;
    for (ll i=1; i<=n; i++) if (visited[i]==false)
    {
        ++ans;
        dfs(i);
    }
    cout<<ans-1;
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