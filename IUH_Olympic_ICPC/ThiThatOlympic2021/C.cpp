#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1000005][5];
const ll mod=1e9+7;

void solve()
{
    string s, t; cin>>s>>t;
    s=" "+s;
    t=" "+t;
    ll n=s.size()-1;

    for (ll i=0; i<=n; i++) dp[i][0]=dp[i][1]=0;
    dp[0][0]=1;
    for (ll i=0; i<n; i++)
    {
        if (s[i+1]=='X') dp[i+1][0]=(dp[i][0]+dp[i][1])%mod;
        if (t[i+1]=='X') dp[i+1][1]=(dp[i][0]+dp[i][1])%mod;
    }
    cout<<(dp[n][0]+dp[n][1])%mod<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}
