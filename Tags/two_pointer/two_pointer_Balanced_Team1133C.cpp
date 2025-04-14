#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
 
void solve()
{
    ll n; cin>>n;
    ll a[n];
    for (ll i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);
    ll ans=0, j=0;
    for (ll i=0; i<n; i++)
    {
        while (j<n && a[j]-a[i]<=5) ++j;
        ans=max(ans, j-i);
    }
    cout<<ans;
}
 
int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("a_input.txt","r",stdin);
    freopen("a_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}