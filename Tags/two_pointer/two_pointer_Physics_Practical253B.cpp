#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve()
{
    ll n, k; cin>>n>>k;
    ll a[n];
    for (ll i=0; i<n; i++) cin>>a[i];
    ll j=0, ans=0, s=0;
    for (ll i=0; i<n; i++)
    {
        s+=a[i];
        while (j<n && s>k) s-=a[j++];
        ans=max(ans, i-j+1);
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