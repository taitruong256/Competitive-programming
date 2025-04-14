/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
ll n, m;
ll f[1005][1005], a[1005][1005];

void truyvet(ll i, ll j)
{
    if (f[i][j]==0) return;
    if (f[i][j-1]+a[i][j]==f[i][j]) truyvet(i, j-1);
    else if (f[i-1][j-1]+a[i][j]==f[i][j]) truyvet(i-1, j-1);
    else truyvet(i+1, j-1);
    cout<<a[i][j]<<" ";
}

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) cin>>a[i][j];
    
    for (ll j=0; j<=m+1; j++)
        for (ll i=0; i<=n+1; i++) f[i][j]=0;
    for (ll j=1; j<=m; j++)
        for (ll i=1; i<=n; i++) f[i][j]=max(  max(  f[i][j-1], f[i-1][j-1]  ), f[i+1][j-1]  )+a[i][j];

    for (ll i=1; i<=n; i++)
    {
        for (ll j=1; j<=m; j++) cout<<f[i][j]<<" ";
        cout<<endl;
    }
    cout<<f[n][m]<<endl;
    truyvet(n, m);
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