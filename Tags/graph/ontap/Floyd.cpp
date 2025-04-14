#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll w[505][505], d[505][505];
ll n, m, q;

void solve()
{
    cin>>n>>m>>q;

    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++)
            if (i==j) d[i][j]=0;
            else d[i][j]=1e18;

    for (ll i=0; i<m; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        d[u][v]=min(d[u][v], w);
        d[v][u]=min(d[v][u], w);
    }

    for (ll k=1; k<=n; k++)
        for (ll i=1; i<=n; i++)
            for (ll j=1; j<=n; j++)
                if (d[i][k]+d[k][j]<d[i][j]) d[i][j]=d[i][k]+d[k][j];

    while (q--)
    {
        ll u, v; cin>>u>>v;
        if (d[u][v]==1e18) cout<<-1<<endl;
        else cout<<d[u][v]<<endl;
    }
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
