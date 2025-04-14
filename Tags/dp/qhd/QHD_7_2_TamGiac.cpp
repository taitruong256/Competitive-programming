/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
ll n;
ll a[10005][10005], f[10005][10005];

void truyvet(ll i, ll j)
{
    if (f[i][j]==0) return;
    if (f[i][j]==f[i-1][j]+a[i][j])
    {
        truyvet(i-1, j);
        cout<<a[i][j]<<" ";
    }
    else 
    {
        truyvet(i-1, j-1);
        cout<<a[i][j]<<" ";
    }
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=i; j++) cin>>a[i][j];

    for (ll i=0; i<=n+1; i++)
        for (ll j=0; j<=n+1; j++) f[i][j]=0;
    f[1][1]=a[1][1];
    for (ll i=2; i<=n; i++) f[i][1]=f[i-1][1]+a[i][1];

    for (ll i=2; i<=n; i++)
        for (ll j=2; j<=i; j++) f[i][j]=max(f[i-1][j], f[i-1][j-1])+a[i][j];

    // for (ll i=1; i<=n; i++)
    // {
    //     for (ll j=1; j<=i; j++) cout<<f[i][j]<<" "; 
    //     cout<<endl;
    // }

    ll index=1, mx=0;
    for (ll i=1; i<=n; i++) if (f[n][i]>mx) mx=f[n][i], index=i;
    cout<<mx<<endl;
    truyvet(n, index);
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