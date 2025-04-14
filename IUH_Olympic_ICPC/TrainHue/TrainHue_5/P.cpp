/*=====================================================================================
                Nothing is impossible, only you think it is impossible
                        Try, try, try again until you succeed
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, x;
ll f[101][50001];

void solve()
{
    cin>>n>>x;
    ll w[n+5], c[n+5];
    for (ll i=1; i<=n; i++) cin>>w[i]>>c[i];

    for (ll i=0; i<=n; i++) f[i][0]=0;
    for (ll i=1; i<=n; i++) f[0][i]=1e9;

    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=x; j++)
            if (j>=w[i]) f[i][j]=min(f[i-1][j], f[i][j-w[i]]+c[i]);
            else f[i][j]=f[i-1][j];

    for (ll i=1; i<=n; i++)
    {
        for (ll j=1; j<=x; j++) cout<<f[i][j]<<" ";
        cout<<endl;
    }
    cout<<f[n][x];
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
