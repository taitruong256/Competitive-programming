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
    ll n, m; cin>>n>>m;
    ll a[n+5];
    pair<ll, ll> b[m+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=m; i++) cin>>b[i].first>>b[i].second;
    sort(b+1, b+m+1);
    b[0].second=0;
    for (ll i=1; i<=m; i++) b[i].second+=b[i-1].second;

    for (ll i=1; i<=n; i++)
    {
        ll l=1, r=m, ans=0;
        while (l<=r)
        {
            ll mid=(l+r)>>1;  //cout<<l<<" "<<r<<" "<<ans<<endl;
            if (b[mid].first<=a[i]) ans=mid, l=mid+1;
            else r=mid-1;  
        }
        cout<<b[ans].second<<" ";
    }
}

int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; //cin>>t;
    while (t--) solve();
    return 0;
}