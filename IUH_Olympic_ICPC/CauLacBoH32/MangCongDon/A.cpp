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
    ll n, x, y, z; cin>>n>>x>>y>>z;
    ll a[n+5], left[n+5], right[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    left[1]=x*a[1];
    for (ll i=2; i<=n; i++) left[i]=max(left[i-1], x*a[i]);
    right[n]=z*a[n];
    for (ll i=n-1; i>=1; i--) right[i]=max(right[i+1], z*a[i]);
    ll ans=-4e18;
    for (ll i=1; i<=n; i++) ans=max(ans, left[i]+y*a[i]+right[i]);
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; //cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}