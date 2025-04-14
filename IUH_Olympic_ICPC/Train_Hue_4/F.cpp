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
    ll n; cin>>n;
    ll a[n+5], b[n+5];
    ll f[n+5][n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) cin>>b[i];

    for (ll i=0; i<=n; i++)
        for (ll j=0; j<=n; j++) f[i][j]=0;

    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++)
            if (a[i]==b[j]) f[i][j]=f[i-1][j-1]+1;
            else f[i][j]=max(f[i-1][j], f[i][j-1]);

    cout<<f[n][n];
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