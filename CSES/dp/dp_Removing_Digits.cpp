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
    ll dp[n+5];
    for (ll i=1; i<=n; i++) dp[i]=1e9;
    // memset(dp, 1e9, sizeof(dp));
    dp[0]=0;
    for (ll i=1; i<=n; i++)
    {
        ll x=i;
        while (x>0)
        {
            dp[i]=min(dp[i], dp[i-x%10]+1);
            x/=10;
        }
    }
    // for (ll i=1; i<=n; i++) cout<<dp[i]<<endl;
    cout<<dp[n];
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