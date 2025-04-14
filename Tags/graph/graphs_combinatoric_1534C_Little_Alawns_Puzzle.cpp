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
typedef int ll;
map<ll, vector<ll>> adj;
vector<bool> visited;
ll n, a[400005][2]; 
const ll mod=1e9+7;

void dfs(ll u)
{
    visited[u]=true;
    for (auto v: adj[u]) if (visited[v]==false) dfs(v);
}

void solve()
{
    cin>>n;
    adj.clear();
    visited.resize(0);
    visited.resize(n+5, false);
    for (ll i=1; i<=n; i++) cin>>a[i][0];
    for (ll i=1; i<=n; i++) cin>>a[i][1];
    for (ll i=1; i<=n; i++)
    {
        ll u=a[i][0];
        ll v=a[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans=1;
    for (ll i=1; i<=n; i++) if (visited[i]==false)
    {
        ans=(ans*2)%mod;
        dfs(i);
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}