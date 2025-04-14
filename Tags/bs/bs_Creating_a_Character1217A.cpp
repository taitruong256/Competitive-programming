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

void solve()
{
    ll a, b, n; cin>>a>>b>>n;
    ll l=0, r=n, ans=1e9;
    while (l<=r)
    {
        ll mid=(l+r)>>1; // cout<<a+mid<<"     "<<b+n-mid<<endl;
        if (a+mid>b+n-mid) ans=mid, r=mid-1;
        else l=mid+1;
    }
    cout<<max(n-ans+1, 0LL)<<endl;
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