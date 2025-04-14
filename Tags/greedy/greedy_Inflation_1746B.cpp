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
    ll n, k; cin>>n>>k;
    ll a[n];
    for (ll i=0; i<n; i++) cin>>a[i];
    ll sum=a[0], ans=0;
    for (ll i=1; i<n; i++) 
    {
        ans=max(ans, (a[i]*100-sum*k+k-1)/k);
        sum+=a[i];
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