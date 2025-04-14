/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve()
{
    string s; cin>>s;
    ll n=s.size();
    s=" "+s;
    ll last[3], dp[n+5];
    memset(last, -1, sizeof(last));
    dp[0]=0;
    last[0]=0;
    ll sum=0;
    for (ll i=1; i<=n; i++)
    {
        sum+=(s[i]-'0');
        sum%=3;
        dp[i]=dp[i-1];
        if (last[sum]!=-1) dp[i]=max(dp[i], dp[last[sum]]+1);
        last[sum]=i;
    }
    // for (ll i=1; i<=n; i++) cout<<dp[i]<<" ";
    cout<<dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}