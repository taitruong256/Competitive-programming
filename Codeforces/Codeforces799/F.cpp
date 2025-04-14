/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

void solve()
{
    ll n; cin>>n;
    ll a[n+5]; 
    for (ll i=1; i<=n; i++) cin>>a[i];
    ll dp[3][10];
    for (ll i=0; i<3; i++)
        for (ll j=0; j<10; j++) dp[i][j]=0;
    for (ll i=1; i<=n; i++)
    {
        for (ll j=0; j<10; j++) if (dp[1][j]==1) dp[2][(j+a[i]%10)%10]=1;
        for (ll j=0; j<10; j++) if (dp[0][j]==1) dp[1][(j+a[i]%10)%10]=1;
        for (ll j=0; j<10; j++) dp[0][a[i]%10]=1;
    }
    if (dp[2][3]==1) cout<<"YES\n";
    else cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}