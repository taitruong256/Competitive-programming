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
    ll n, k; cin>>n>>k;
    map<ll, ll> cnt;
    ll mx=0;
    for (ll i=0; i<n; i++)
    {
        ll x; cin>>x;
        if (x%k!=0) ++cnt[k-x%k];
        mx=max(mx, cnt[k-x%k]);
    }
    if (mx==0)
    {
        cout<<0<<endl;
        return;
    }
    ll ans=0;
    for (auto i: cnt) if (i.second==mx) ans=max(ans, k*(mx-1)+i.first+1);
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}