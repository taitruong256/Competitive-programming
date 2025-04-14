#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define orderset tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
ll n, m, in[100005];
vector<ll> adj[100005];
bool vis[100005];

void solve()
{
    cin>>n>>m;
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        ++in[v];
    }
    if (adj[1].size()-in[1]!=1 || adj[n].size()-in[n]!=-1)
    {
        cout<<"IMPOSSIBLE";
        return;
    }
    for (ll i=2; i<=n-1; i++) if (adj[i].size()!=in[i])
    {
        cout<<"IMPOSSIBLE";
        return;
    }
    stack<ll> st;
    vector<ll> path;
    st.push(1);
    vis[1]=true;
    while (!st.empty())
    {
        ll u=st.top();
        if (!adj[u].empty())
        {
            ll v=adj[u].back();
            adj[u].pop_back();
            st.push(v);
        }
        else
        {
            ll v=st.top(); st.pop();
            path.push_back(v);
        }
    }
    if (path.size()<m+1)
    {
        cout<<"IMPOSSIBLE";
        return;
    }
    reverse(path.begin(), path.end());
    for (auto i: path) cout<<i<<" ";
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
