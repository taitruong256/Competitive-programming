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
ll f[105][100005];

void solve()
{
    cin>>n>>x;
    ll w[n+5], c[n+5];
    for (ll i=1; i<=n; i++) cin>>w[i]>>c[i];

    for (ll i=0; i<=n; i++) f[i][0]=0;
    for (ll i=1; i<=100004; i++) f[0][i]=1e9;

    for (ll i=1; i<=n; i++)
    {
        for (ll j=1; j<=100004; j++)
            if (j>=w[i]) f[i][j]=min(f[i-1][j], f[i][j-w[i]]+c[i]);
            else f[i][j]=f[i-1][j];
    }
    ll ans=1e18;
    for (ll i=x; i<=100004; i++) ans=min(ans, f[n][i]);
    cout<<ans;
    //if (f[n][x]==1e9) cout<<-1; else cout<<f[n][x]<<endl;
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

