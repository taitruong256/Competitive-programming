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
    ll n, k; cin>>n>>k;
    ll a[n];
    for (ll i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);
    ll sum=0;
    for (ll i=n/2; i<n; i++) sum+=a[i];
    cout<<(sum+k)/(n/2+1);
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