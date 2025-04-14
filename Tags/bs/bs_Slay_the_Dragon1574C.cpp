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
    ll a[n], sum=0;
    for (ll i=0; i<n; i++) 
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a, a+n);
    ll m; cin>>m;
    while (m--)
    {
        ll x, y; cin>>x>>y;
        ll ans=2e18, now=lower_bound(a, a+n, x)-a;
        if (now>0) ans=min(ans, x-a[now-1]+max(0LL, y-sum+a[now-1]));
        if (now<n) ans=min(ans, max(0LL, y-sum+a[now]));
        cout<<ans<<endl;
    }
}

int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; 
    while (t--) solve();
    return 0;
}