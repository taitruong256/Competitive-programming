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
#define mod 1000000007
ll dp[1000005][10];

void solve()
{
    ll n; cin>>n;
    cout<<(dp[n][3]+dp[n][7])%mod<<endl;    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    for (ll j=1; j<=8; j++) dp[1][j]=1;
    
    for (ll i=2; i<=1e6; i++) 
        for (ll j=1; j<=8; j++)
        {
            if (j==1 || j==2 || j==3 || j==5 || j==6) 
                dp[i][j]=(dp[i-1][1]+dp[i-1][3]+dp[i-1][4]+dp[i-1][5]+dp[i-1][6])%mod;
            else 
                dp[i][j]=(dp[i-1][2]+dp[i-1][7]+dp[i-1][8])%mod;
        }
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}