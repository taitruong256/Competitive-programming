#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve()
{  
    ll n; cin>>n;
    ll a[n]; 
    for (ll i=0; i<n; i++) cin>>a[i];

    ll minn=2e9+5, ans=0;
    for (ll i=n-1; i>=0; i--)
    {
        if (i<minn) ++ans;
        minn=min(minn, i-a[i]);
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