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
    ll a[n+5], b[m+5], dp[n+5][1030];
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=m; i++) cin>>b[i];

    memset(dp, 0, sizeof(dp));
    dp[0][0]=1;
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=0;k<1024;k++)
                if(dp[i-1][k])
                    dp[i][k|(a[i]&b[j])]=1;

    for (ll i=0; i<(1<<9); i++) if (dp[n][i]==1) 
    {
        cout<<i;
        return;
    }
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