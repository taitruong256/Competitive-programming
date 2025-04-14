/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long 
const ll mod=1e9+7;

int tinh(int l, int r) {
    if(r == 0) return l / 3;
    else return l / 3 + (l % 3 >= r);
}

void solve()
{
    ll n, l, r ;cin>>n>>l>>r;
    ll dp[n+5][3];
    dp[1][0]=tinh(r, 0)-tinh(l-1, 0);
    dp[1][1]=tinh(r, 1)-tinh(l-1, 1);
    dp[1][2]=tinh(r, 2)-tinh(l-1, 2);

    for (ll i=2; i<=n; i++)
        {
            dp[i][0]=(dp[i-1][1]*dp[1][2]%mod+dp[i-1][2]*dp[1][1]%mod+dp[i-1][0]*dp[1][0]%mod)%mod;
            dp[i][1]=(dp[i-1][1]*dp[1][0]%mod+dp[i-1][0]*dp[1][1]%mod+dp[i-1][2]*dp[1][2]%mod)%mod;
            dp[i][2]=(dp[i-1][0]*dp[1][2]%mod+dp[i-1][2]*dp[1][0]%mod+dp[i-1][1]*dp[1][1]%mod)%mod;
        }
    cout<<dp[n][0];
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