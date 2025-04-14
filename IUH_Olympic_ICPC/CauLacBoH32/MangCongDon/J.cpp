/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
void solve()
{
    ll n, k; cin>>n>>k;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    ll sum[n+5]={0};
    for (ll i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];
    ll ans=1, mn=1e10;
    for (ll i=1; i<=n-k+1; i++)
    {
        // for (ll j=i; j<=i+k-1; j++) cout<<a[j]<<" ";
        // cout<<endl;
        if (sum[i+k-1]-sum[i-1]<mn)
        {
            mn=sum[i+k-1]-sum[i-1];
            ans=i;
        } 
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;// cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}