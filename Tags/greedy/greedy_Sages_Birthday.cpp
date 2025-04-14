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
    ll n; cin>>n;
    ll a[n], ans[n];
    for (ll i=0; i<n; i++) cin>>a[i];
    sort(a, a+n, greater<ll>());
    ll k=0;
    for (ll i=n-1; i>=0; i-=2) ans[i]=a[k++];
    for (ll i=n-2; i>=0; i-=2) ans[i]=a[k++];
    cout<<(n-1)/2<<endl;
    for (ll i=0; i<n; i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;// cin>>t;
    while (t--) solve();
    return 0;
}