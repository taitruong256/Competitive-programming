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
    ll a[n+5][m+5];
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) cin>>a[i][j];
    ll f[5][n+5][m+5];
    memset(f, 0, sizeof(f));

    for (ll i=1; i<=n; i++)    //1 1
        for (ll j=1; j<=m; j++)
            f[0][i][j]=max(f[0][i-1][j], f[0][i][j-1])+a[i][j];
    
    for (ll i=n; i>=1; i--)   // n m
        for (ll j=m; j>=1; j--)
            f[1][i][j]=max(f[1][i+1][j], f[1][i][j+1])+a[i][j];

    for (ll i=n; i>=1; i--)     // n 1
        for (ll j=1; j<=m; j++)
            f[2][i][j]=max(f[2][i][j-1], f[2][i+1][j])+a[i][j];

    for (ll i=1; i<=n; i++)    //1 m
        for (ll j=m; j>=1; j--)
            f[3][i][j]=max(f[3][i][j+1], f[3][i-1][j])+a[i][j];

    ll ans=0;
    for (ll i=2; i<=n-1; i++)
        for (ll j=2; j<=m-1; j++)
        {
            ans=max(ans, f[0][i][j-1]+f[1][i][j+1]+f[2][i+1][j]+f[3][i-1][j]);
            ans=max(ans, f[0][i-1][j]+f[1][i+1][j]+f[2][i][j-1]+f[3][i][j+1]);
        }
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