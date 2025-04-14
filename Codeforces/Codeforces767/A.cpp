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
    pair<ll, ll> a[n+5];
    ll ans=k;
    for (ll i=0; i<n; i++) cin>>a[i].first;
    for (ll i=0; i<n; i++) cin>>a[i].second;

    sort(a, a+n);
    for (ll i=0; i<n; i++) if (ans>=a[i].first) ans+=a[i].second;
      else break;
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