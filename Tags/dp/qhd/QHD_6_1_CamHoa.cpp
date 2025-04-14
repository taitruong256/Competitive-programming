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
ll f[10005][10005], a[10005][10005];

void truyvet(ll i, ll j)
{
    if (f[i][j]==0) return;
    if (f[i][j]==f[i-1][j-1]+a[i][j])
    {
        truyvet(i-1, j-1);
        cout<<i<<" "<<j<<endl;
    }
    else truyvet(i, j-1);
}

void solve()
{
    cin>>m>>n;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) cin>>a[i][j];

    for (ll i=0; i<=n+1; i++)
        for (ll j=0; j<=m+1; j++) f[i][j]=0;

    for (ll i=0; i<=n; i++)
        for (ll j=i; j<=m; j++) 
            if (i==0 || j==0) f[i][j]=0;
                else if (i==j) f[i][j]=f[i-1][j-1]+a[i][j];
                    else if (i<j) f[i][j]=max(f[i][j-1], f[i-1][j-1]+a[i][j]);

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