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
    ll a[n+5], b[n+5], dp[n+5][n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) cin>>b[i];
    ll sum=0;
    for (ll i=1; i<=n; i++) sum+=a[i]*b[i];
    memset(dp, 0, sizeof(dp));
    for (ll i=1; i<=n; i++) dp[i][i]=dp[i][i-1]=sum;
    ll ans=sum;
    for (ll len=2; len<=n; len++)
    {
        for (ll l=1; l+len-1<=n; l++)
        {
            ll r=l+len-1;
            dp[l][r]=dp[l+1][r-1]+a[l]*b[r]+a[r]*b[l]-a[l]*b[l]-a[r]*b[r];
            ans=max(ans, dp[l][r]);
        }
    }

    // for (ll i=1; i<=n; i++)
    // {
    //     for (ll j=1; j<=n; j++) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
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