#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll n, m, k; 
char c[105][105];
ll dp[(1LL<<18)][18], d[105][105], id[105][105], vis[105][105], idx=0;
ll dx[]={0, 0, 1, -1};
ll dy[]={1, -1, 0, 0};

void bfs(ll x, ll y)
{
    queue<pair<ll, ll>> q;
    q.push({x, y});
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++)
            vis[i][j]=-1;
    vis[x][y]=0;
    d[id[x][y]][id[x][y]]=0;
    while (!q.empty())
    {
        auto [u, v]=q.front(); q.pop();
        for (ll i=0; i<4; i++)
        {
            ll newx=u+dx[i];
            ll newy=v+dy[i];
            if (1<=newx && newx<=n && 1<=newy && newy<=m && c[newx][newy]!='#' && vis[newx][newy]==-1) 
            {
                q.push({newx, newy});
                vis[newx][newy]=vis[u][v]+1;
                if (c[newx][newy]=='S')
                {
                    ll id1=id[x][y];
                    ll id2=id[newx][newy];
                    d[id1][id2]=min(d[id1][id2], vis[newx][newy]);
                    d[id2][id1]=min(d[id2][id1], vis[newx][newy]);
                }
            }
        }
    }
}

void solve()
{
    cin>>n>>m>>k;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) 
            cin>>c[i][j];
    
    for (ll i=1; i<=n+1; i++)
        for (ll j=1; j<=n+1; j++)
            d[i][j]=1e18;

    c[1][1]='S';
    for (ll i=1; i<=n; i++) 
        for (ll j=1; j<=m; j++)
            if (c[i][j]=='S')
            {
                id[i][j]=++idx;
                bfs(i, j);
            }

    // for (ll i=1; i<=k+1; i++)
    // {
    //     for (ll j=1; j<=k+1; j++) cout<<d[i][j]<<" ";
    //     cout<<endl;
    // }

    // for (ll i=1; i<=n; i++)
    // {
    //     for (ll j=1; j<=m; j++) cout<<id[i][j]<<" ";
    //     cout<<endl;
    // }

    n=k+1;
    for (ll mask=0; mask<(1LL<<n); mask++) 
        for (ll i=0; i<n; i++)
            dp[mask][i]=1e18;
    for (ll i=1; i<n; i++) dp[(1LL<<i)][i]=d[1][i+1];

    for (ll mask=0; mask<(1<<n); mask++)
    {
      for (ll u=0; u<n; u++) if (mask&(1<<u)) 
      {
        ll old_mask=mask^(1<<u);   
        for (ll v=0; v<n; v++) if (old_mask&(1<<v) && u!=v)
        {   
          dp[mask][u]=min(dp[old_mask][v]+d[v+1][u+1], dp[mask][u]);
        }
      }
    }

    ll ans=1e18;
    for (ll i=0; i<n; i++) ans=min(ans, dp[(1<<n)-1][i]);
    if (ans==1e18) ans=-1;
    cout<<ans<<endl;

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}
