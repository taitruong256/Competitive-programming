/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
 =====================================================================================
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
ll n, s; 
ll a[200005];

bool check(ll x)
{
    ll sum=0;
    for (ll i=0; i<n; i++) if (a[i]<x) sum+=a[i];
    return sum<=s;
}

void solve()
{
    cin>>n>>s;
    for (ll i=0; i<n; i++) cin>>a[i];
    ll l=0, r=1e18, ans=0;
    while (l<=r)
    {
        ll mid=(l+r)>>1;      //cout<<mid<<endl;
        if (check(mid)) ans=mid, l=mid+1;
        else r=mid-1;
    }
    ll res=0;
    for (ll i=0; i<n; i++) if (a[i]>=ans) 
    {
        res=i+1;
        break;
    }
    cout<<res<<endl;
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