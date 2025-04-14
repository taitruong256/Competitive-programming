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
const ll mod=1e9+7;
ll n, k, sz; 
map<ll, vector<ll>> adj;
vector<bool> visited;

void dfs(ll u)
{
    ++sz;
    visited[u]=true;
    for (auto v: adj[u]) if (visited[v]==false) dfs(v);
}

void solve()
{
    cin>>n>>k;
    for (ll i=0; i<n-1; i++)
    {
        ll u, v, c; cin>>u>>v>>c;
        if (c==0) adj[u].push_back(v), adj[v].push_back(u);
    }
    visited.resize(0);
    visited.resize(n+5, false);
    ll ans=1, res=0;
    for (ll i=0; i<k; i++) ans=(ans*n)%mod;
    for (ll i=1; i<=n; i++) if (visited[i]==false)
    {
        sz=0;
        dfs(i);
        ll p=1;
        for (ll i=0; i<k; i++) p=(p*sz)%mod;
        res=(res+p)%mod;
    }
    ans=(ans-res+mod)%mod;
    cout<<ans;
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