#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                    Try, try, try again until you succeed     
                      Where is the bug, delete it there                     
 =====================================================================================
*/

void solve()
{           
    ll n, h; cin>>n>>h;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    ll l=0, r=1e18, ans=0;
    while (l<=r)
    {
        ll mid=(l+r)>>1;
        ll sum=mid;
        for (ll i=1; i<n; i++) sum+=min(a[i+1]-a[i], mid);
        if (sum>=h) ans=mid, r=mid-1;
        else l=mid+1;
    }
    cout<<ans<<endl;
}

int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; cin>>t;
    while (t--) solve();
    return 0;
}