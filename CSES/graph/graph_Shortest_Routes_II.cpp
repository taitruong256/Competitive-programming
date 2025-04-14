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
const ll inf = 1e18;
ll n, m, q;
ll w[505][505], d[505][505];

void solve()
{
    for (ll i=1; i<=500; i++)
        for (ll j=1; j<=500; j++) 
            if (i!=j) w[i][j]=inf;
            else w[i][j]=0;
    
    cin>>n>>m>>q;
    for (ll i=0; i<m; i++)
    {
        ll u, v, c; cin>>u>>v>>c;
        c=min(c, w[u][v]);
        w[u][v]=c;
        w[v][u]=c;
    }
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) d[i][j]=w[i][j];

    for (ll k=1; k<=n; k++) 
        for (ll i=1; i<=n; i++)
            for (ll j=1; j<=n; j++)
                if (d[i][k]<inf && d[k][j]<inf && d[i][k]+d[k][j]<d[i][j]) d[i][j]=d[i][k]+d[k][j];
    
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) if (d[i][j]==inf) d[i][j]=-1;
    
    while (q--)
    {
        ll a, b; cin>>a>>b;
        cout<<d[a][b]<<endl;
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