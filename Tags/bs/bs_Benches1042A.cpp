/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m; 
ll a[105];

bool check(ll x)
{
    ll t=m;
    for (ll i=0; i<n; i++) if (t>0) t-=(x-a[i]);
    return t<=0;
}

void solve()
{
    cin>>n>>m;
    ll mx=0;
    for (ll i=0; i<n; i++)
    {
        cin>>a[i];
        mx=max(mx, a[i]);
    }                           

    ll l=0, r=1e9, ans=0;
    while (l<=r)
    {
        ll mid=(l+r)>>1;
        if (check(mid)) ans=mid, r=mid-1;
        else l=mid+1;   
    }
    if (ans<mx) ans=mx;
    cout<<ans<<" "<<mx+m;
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