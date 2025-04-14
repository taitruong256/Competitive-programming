/*=====================================================================================
    Nothing is impossible, only you think it is impossible                 
            Try, try, try again until you succeed     
              Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll dinh, pos;
};

vector<vector<pair<ll, ll>>> adj;
ll n;
ll ans[100005];

void dfs(pair<ll, ll> u, ll par, ll val)
{
    ans[u.second]=val;
    for (auto it: adj[u.first]) if (it.first!=par) dfs(it, u.first, 5-val);
}

void solve()
{
    cin>>n;
    adj.resize(0);
    adj.resize(n+5);
    for (ll i=1; i<=n-1; i++) 
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    for (ll i=1; i<=n; i++) if (adj[i].size()>2)
    {
        cout<<-1<<endl;
        return;
    }
    pair<ll, ll> root;
    for (ll i=1; i<=n; i++) if (adj[i].size()==1) root={i, 0};
    dfs(root, 0, 2);

    for (ll i=1; i<=n-1; i++) cout<<ans[i]<<" "; cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  cin>>t;
    while (t--) solve();
    return 0;
}