#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve()
{
    ll n, d; cin>>n>>d;
    ll a[n];
    for (ll i=0; i<n; i++) cin>>a[i];
    ll i=0, ans=0;
    for (ll j=2; j<n; j++)
    {
        while (i<j && a[j]-a[i]>d) ++i;
        ans+=(j-i)*(j-i-1)/2;
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