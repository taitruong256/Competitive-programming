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
#define ll int
bool d[4005][4005];
ll deg[4005];

void solve()
{
    memset(deg, 0, sizeof(deg));
    ll n, m; cin>>n>>m;
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        d[u][v]=d[v][u]=true;
        ++deg[u];
        ++deg[v];
    }

    ll ans=1e9;
    for (ll i=1; i<=n; i++)
        for (ll j=i+1; j<=n; j++) if (d[i][j]==true)
            for (ll k=j+1; k<=n; k++) if (d[i][k]==true && d[j][k]==true)
                ans=min(ans, deg[i]+deg[j]+deg[k]-6);
    if (ans==1e9) ans=-1;
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}