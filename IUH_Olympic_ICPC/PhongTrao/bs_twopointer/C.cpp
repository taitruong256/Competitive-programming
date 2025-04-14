/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    for (ll i=0; i<n; i++) cin>>a[i];
    if (n==1)
    {
        cout<<0<<endl;
        return;
    }
    map<ll, ll> cnt; 
    ll ans=1;
    for (ll i=0; i<n; i++) ++cnt[a[i]];
    for (ll i=0; i<n; i++)
    {
        ll x=min((ll)cnt.size(), cnt[a[i]]-1);
        ll y=min((ll)cnt.size()-1, cnt[a[i]]);
        ans=max(ans, x);
        ans=max(ans, y);
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
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}