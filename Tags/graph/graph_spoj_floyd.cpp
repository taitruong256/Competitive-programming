/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18;
ll n, m, q;
ll d[505][505], trace[505][505], w[505][505];

void floyd()
{
    for (ll i=0; i<=n; i++)
        for (ll j=0; j<=n; j++) trace[i][j]=i;

    for (ll i=0; i<=n; i++)
        for (ll j=0; j<=n; j++) d[i][j]=w[i][j];

    for (ll k=0; k<=n; k++)
        for (ll i=0; i<=n; i++)
            for (ll j=0; j<=n; j++) 
                if (d[i][k]<INF && d[k][j]<INF && d[i][k]+d[k][j]<d[i][j])
                {
                    d[i][j]=d[i][k]+d[k][j];
                    trace[i][j]=trace[k][j];
                }
}

vector<ll> truyvet(ll u, ll v)
{
    vector<ll> path;
    while (v!=u)
    {
        path.push_back(v);
        v=trace[u][v];
    }
    path.push_back(u);
    reverse(path.begin(), path.end());
    return path;
}

void solve()
{
    cin>>n>>m>>q;
    for (ll i=0; i<=n; i++)
        for (ll j=0; j<=n; j++) if (i==j) w[i][j]=0; else w[i][j]=INF;
    
    for (ll i=0; i<m; i++)
    {
        ll x, y, c; cin>>x>>y>>c; 
        w[x][y]=c; 
        w[y][x]=c; 
    }
    
    floyd();
    for (ll i=0; i<q; i++)
    {
        ll t, x, y; cin>>t>>x>>y;
        if (t==0) cout<<d[x][y]<<endl;
        else 
        {
            vector<ll> p=truyvet(x, y);
            cout<<p.size()<<" ";
            for (auto it: p) cout<<it<<" "; cout<<endl;
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