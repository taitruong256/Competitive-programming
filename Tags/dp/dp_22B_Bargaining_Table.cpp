/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, m; cin>>n>>m;
    char a[n+5][m+5];
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) cin>>a[i][j];
    ll sum[n+5][m+5];
    memset(sum, 0, sizeof(sum));
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j]-'0';
    
    ll ans=0;
    for (ll x1=1; x1<=n; x1++)
        for (ll y1=1; y1<=m; y1++)
            for (ll x2=x1; x2<=n; x2++)
                for (ll y2=y1; y2<=m; y2++)
                    if (sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]==0)
                        ans=max(ans, 2*(x2-x1+1+y2-y1+1));
    cout<<ans;
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