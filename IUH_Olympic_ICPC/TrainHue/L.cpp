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
ll d[1000][1000], w[1000][1000];


void floyd()
{
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) d[i][j]=w[i][j];
    for (ll i=1; i<=n; i++) d[i][i]=0;

    for (ll k=1; k<=n; k++)
        for (ll i=1; i<=n; i++)
            for (ll j=1; j<=n; j++) 
                if (d[i][k]<INF && d[k][j]<INF && d[i][k]+d[k][j]<d[i][j])
                    d[i][j]=d[i][k]+d[k][j];
}

void solve()
{
    cin>>n>>m>>q;
    for (ll i=0; i<=n; i++)
        for (ll j=0; j<=n; j++) w[i][j]=INF;
    for (ll i=0; i<=n; i++)
        for (ll j=0; j<=n; j++) d[i][j]=INF;
    
    for (ll i=0; i<m; i++)
    {
        ll u, v, c; cin>>u>>v>>c; 
        w[u][v]=min(w[u][v], c);
        w[v][u]=min(w[v][u], c);
    }
    floyd();

    --q;
    while (q--)
    {
        ll u, v; cin>>u>>v;
        if (d[u][v]!=INF) cout<<d[u][v]<<endl;
        else cout<<-1<<endl;
    }
    ll u, v; cin>>u>>v;
    if (d[u][v]!=INF) cout<<d[u][v];
    else cout<<-1;
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