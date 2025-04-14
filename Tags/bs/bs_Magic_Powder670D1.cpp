/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
ll a[200005], b[200005];

bool check(ll x)
{
    ll t=k;
    for (ll i=0; i<n; i++) 
    {
        if (a[i]*x<=b[i]) continue;
        t-=a[i]*x-b[i];
        if (t<0) return false;
    }
    return t>=0;
}

void solve()
{
    cin>>n>>k;
    for (ll i=0; i<n; i++) cin>>a[i];
    for (ll i=0; i<n; i++) cin>>b[i];

    ll l=0, r=2e9+5, ans=0;
    while (l<=r)
    {
        ll mid=(l+r)>>1;
        if (check(mid)) ans=mid, l=mid+1;
        else r=mid-1;
    }
    cout<<ans;
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