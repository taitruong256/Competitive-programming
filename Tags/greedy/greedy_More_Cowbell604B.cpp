/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, k, ans=0; cin>>n>>k;
    ll a[n+5];
    for (ll i=0; i<n; i++) cin>>a[i];
    for (ll i=0; i<n; i++) if (a[i]>ans) ans=a[i];

    if (k>=n)
    {
        cout<<ans<<endl;
        return;
    }
    for (ll i=0; i<n-k; i++) ans=max(ans, a[i]+a[2*(n-k)-1-i]);
    cout<<ans;
}

int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;
    while (t--) solve();
    return 0;
}