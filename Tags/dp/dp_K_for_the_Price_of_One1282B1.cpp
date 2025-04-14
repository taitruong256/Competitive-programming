/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, p, k; cin>>n>>p>>k;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);
    ll dp[n+5]={0};
    for (ll i=1; i<k; i++) dp[i]=dp[i-1]+a[i];
    for (ll i=k; i<=n; i++) dp[i]=min(dp[i-1], dp[i-k])+a[i];

    ll ans=0;
    for (ll i=1; i<=n; i++) if (dp[i]<=p) ans=i;
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}