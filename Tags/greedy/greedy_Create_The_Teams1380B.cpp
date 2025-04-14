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
    ll n, x; cin>>n>>x;
    ll a[n+5];
    for (ll i=0; i<n; i++) cin>>a[i];
    sort(a, a+n, greater<ll>());
    ll cnt=0, ans=0;
    for (ll i=0; i<n; i++)
    {
        ++cnt;
        if (a[i]*cnt>=x) ++ans, cnt=0;
    }
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