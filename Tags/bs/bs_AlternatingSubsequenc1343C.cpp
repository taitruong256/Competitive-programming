#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve()
{
    ll n; cin>>n;
    ll a[n], b[n], c[n];
    for (ll i=0; i<n; i++) cin>>a[i];
    for (ll i=0; i<n; i++) cin>>b[i];
    for (ll i=0; i<n; i++) c[i]=a[i]-b[i];
    sort(c, c+n);  

    ll ans=0;
    for (ll i=0; i<n; i++)
    {
        ll pos=lower_bound(c+i+1, c+n, -c[i]+1)-c;
        ans+=n-pos;  
    }
    cout<<ans<<endl;
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
