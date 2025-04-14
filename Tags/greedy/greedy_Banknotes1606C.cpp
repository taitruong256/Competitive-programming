/*=====================================================================================
    Nothing is impossible, only you think it is impossible                 
            Try, try, try again until you succeed     
              Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, k; cin>>n>>k;
    ll a[n+5];
    for (ll i=1; i<=n; i++)
    {
        ll x;cin>>x;
        a[i]=1;
        while (x--) a[i]*=10;
    }
    
    ++k;
    ll ans=0;
    for (ll i=1; i<n; i++)
    {
        ll cnt=min(k, a[i+1]/a[i]-1);
        ans+=cnt*a[i];
        k-=cnt;
    }
    ans+=k*a[n];
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  cin>>t;
    while (t--) solve();
    return 0;
}