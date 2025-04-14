/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m; 
vector<ll> canh[50005], topo;
ll deg[10005];

void Kahn()
{
    queue<ll> q;
    for (ll i=1; i<=n; i++) if (deg[i]==0) q.push(i);
    while (!q.empty())
    {
        ll u=q.front(); q.pop();
        topo.push_back(u);
        for (auto v: canh[u]) 
        {
            --deg[v];
            if (deg[v]==0) q.push(v);
        }
    }
}

void solve()
{
    cin>>n>>m;
    memset(deg, 0, sizeof(deg));
    for (ll i=1; i<=m; i++)
    {
        ll u, v; cin>>u>>v;
        canh[u].push_back(v);
        ++deg[v];
    }
    Kahn();
    if (topo.size()<n) cout<<"!DAG";
    else for (auto i: topo) cout<<i<<" ";
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