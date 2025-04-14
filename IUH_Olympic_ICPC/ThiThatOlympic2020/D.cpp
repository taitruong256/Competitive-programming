#include<bits/stdc++.h>
using namespace std;
#define ll int
#define endl '\n'
ll n, par[1000005], a[1000005], height[1000005];
vector<ll> adj[1000005];
set<ll> leaf;
bool vis[1000005];

void dfs(ll u)
{
    vis[u]=true;
    for (auto v: adj[u]) if (vis[v]==false)
    {
        height[v]=height[u]+1;
        dfs(v);
    }
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++)
    {
        cin>>a[i];
        ++par[a[i]];
    }
    for (ll i=1; i<=n+2; i++) if (par[i]==0) leaf.insert(i);
    for (ll i=1; i<=n; i++)
    {
        ll j=*leaf.begin();
        leaf.erase(j);
        adj[a[i]].push_back(j);
        adj[j].push_back(a[i]);
        --par[a[i]];
        if (par[a[i]]==0) leaf.insert(a[i]);
    }
    ll u=*leaf.begin();
    ll v=*leaf.rbegin();
    adj[u].push_back(v);
    adj[v].push_back(u);

    ll st=1;
    for (ll i=1; i<=n+2; i++) if (adj[i].size()==1) st=i;
    dfs(st);
    st=1;
    for (ll i=1; i<=n+2; i++) if (height[i]>height[st]) st=i;
    for (ll i=1; i<=n+2; i++) vis[i]=false, height[i]=0;
    dfs(st);
    ll ans=0;
    for (ll i=1; i<=n+2; i++) ans=max(ans, height[i]);
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    solve();
    return 0;
}
