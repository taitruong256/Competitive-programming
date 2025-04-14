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
ll n;
pair<ll, ll> a[200005];
bool check(ll x)
{
    ll sum=0;
    for (ll i=1; i<=n; i++) if (a[i].first>x) sum+=a[i].second;
    return sum<=x;
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i].first;
    for (ll i=1; i<=n; i++) cin>>a[i].second;
    //sort(a+1, a+n+1);

    ll l=0, r=1e18, ans=0;
    while (l<=r)
    {
        ll mid=(l+r)>>1;  
        if (check(mid)) ans=mid, r=mid-1;
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