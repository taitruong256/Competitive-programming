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
ll n, q, t=0;
vector<ll> adj[200005];
ll a[200005], bit[400005], time_in[200005], time_out[200005];
bool vis[200005];

void update(ll index, ll val)
{
    for (ll i=index; i<=n*2; i+=i&-i) bit[i]+=val;
}

ll query(ll index)
{
    ll sum=0;
    for (ll i=index; i>0; i-=i&-i) sum+=bit[i];
    return sum;
}

void dfs(ll u)
{
    vis[u]=true;
    time_in[u]=++t;
    for (auto v: adj[u]) if (vis[v]==false) dfs(v);
    time_out[u]=t;
}

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<n; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(vis, false, sizeof(vis));
    memset(bit, 0, sizeof(bit));
    dfs(1);
    for (ll i=1; i<=n; i++) 
    {
        update(time_in[i], a[i]);
        update(time_out[i]+1, -a[i]);
    }
    // for (ll i=1; i<=n; i++) cout<<time_in[i]<<" "<<time_out[i]<<endl;
    // for (ll i=1; i<=2*n; i++) cout<<bit[i]<<" "; cout<<endl;

    while (q--)
    {
        ll t; cin>>t;
        if (t==1)
        {
            ll x, k; cin>>x>>k;
            update(time_in[x], -a[x]);
            update(time_out[x]+1, a[x]);
            update(time_in[x], k);
            update(time_out[x]+1, -k);
            a[x]=k;
        }
        else 
        {
            ll x; cin>>x;
            cout<<query(time_in[x])<<endl;
        }
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