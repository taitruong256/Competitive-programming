#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, vector<ll>> ke;
vector<ll> color;

bool bfs(ll u)
{
    queue<ll> q;
    q.push(u);
    color[u]=0;
    while (!q.empty())
    {
        ll v=q.front(); q.pop();
        for (auto k: ke[v])
            if (color[k]==-1)
            {
                q.push(k);
                color[k]=1-color[v];
            }
            else if (color[k]==color[v]) return false;
    }
    return true;
}



void solve()
{
    ll n, m; cin>>n>>m;
    color.resize(n+5, -1);
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }


    for (ll i=1; i<=n; i++) if (color[i]==-1) bfs(i);
    for (ll i=1; i<=n; i++) if (color[i]==1) cout<<i<<" "; cout<<endl;
    for (ll i=1 ;i<=n; i++) if (color[i]==0) cout<<i<<" "; cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("dothihaiphia.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    solve();
    return 0;
}
